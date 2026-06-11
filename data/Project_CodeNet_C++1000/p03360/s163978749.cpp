#include <iostream>

int main(){
    int A,B,C,K,Max, Bandeira = 0;
    int i;

    scanf("%d %d %d", &A, &B, &C);
    scanf("%d", &K);

    Max = A;
    Bandeira = 1;
    if(Max < B){
        Max = B;
        Bandeira = 2;
    }
    if(Max < C){
        Max = C;
        Bandeira = 3;
    }
    for(i = 0; i < K;i++){
        Max = Max * 2;
    }
    if(Bandeira == 1){
        Max = Max + B + C;
    }else if(Bandeira == 2){
        Max = A + Max + C;
    }else if(Bandeira == 3){
        Max = A + B + Max;
    }
    printf("%d", Max);

    return 0;
}