#include <iostream>

using namespace std;

int main(){

    int A, B, C, K, maiora = 0, maiorb = 0, maiorc = 0, soma = 0;

    cin >> A >> B >> C >> K;

    if(A > B && A > C){
        maiora = A;
    }else if(B > A && B > C){
        maiorb = B;
    }else if(C > A && C > B){
        maiorc = C;
    }else{
        for(int i = 0; i < K; i++){
            A *= 2;
            soma = A + B + C;
        }
    }

    if(maiora){
        for(int i = 0; i < K; i++){
            maiora *= 2;
        }
        soma = maiora + B + C;
    }else if(maiorb){
        for(int i = 0; i < K; i++){
            maiorb *= 2;
        }
        soma = A + maiorb + C;
    }else if(maiorc){
        for(int i = 0; i < K; i++){
            maiorc *= 2;
        }
        soma = A + B + maiorc;
    }

    cout << soma << endl;

    return 0;
}
