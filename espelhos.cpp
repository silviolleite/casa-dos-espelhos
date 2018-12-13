#include <iostream>

using namespace std;

// resolução com matriz
long long possibilidades(int n, int r){
    int inc=1;
    int dec=0;
    long long matriz [r][n];
    for(int i=0; i<r;i++){
        dec = n-2;
        for(int j = 0;j<n;j++)
            matriz[i][j] = (i==0) ? inc++ : matriz[i][j] = (j == 0) ? matriz[(i-1)][(inc-2)] : matriz[i][(j-1)] + matriz[(i-1)][(dec--)];
    }
    return matriz[r-1][n-1];
}
int main()
{
    int reflexoes=1, espelhos=1;
    long long resultado;
    while(espelhos>0){
    cout << " ===== Casa dos Espelhos =====" << endl;
    cout << endl;
    cout << "Digite numeoro menor ou igual a zero espelhos para sair do programa" << endl;
    cout << "Digite o numero de espelhos: ";
    cin >> espelhos;
    if(espelhos == 0)
        break;
    do{
    cout << "Digite o numero de reflexoes: ";
    cin >> reflexoes;
    if(reflexoes<0)
        cout << "Numero de reflexões inválido numero precisa ser maior que zero." << endl;
    }while(reflexoes < 0);
    // casos especiais
    if(reflexoes == 1){
        resultado = espelhos;
    }else{
        if(espelhos == 1){
            resultado = 0;
        }else{
            if(espelhos == 2){
                resultado = 1;
            }else{
                //se não for nenhum dos casos especiais chama a função
                resultado = possibilidades(espelhos-1,reflexoes);
            }
        }
    }
    cout << endl;
    cout << "=================================" << endl;
    cout << endl;
    cout << "Numero de possibilidades para " << espelhos << " espelhos e ";
    cout << reflexoes << " reflexoes: " << resultado << " possibilidades" << endl;
    cout << endl;
    cout << "=================================" << endl;
    cout << endl;
    cout << endl;
    }
    cout <<endl;
    cout << "PROGRAMA ENCERRADO!!!"<< endl;
    return 0;
}

