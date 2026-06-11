#include <iostream>

int main(){
    int N, i;
    scanf("%d", &N);
    for(i = N; i <= 2*N; i++){
        if((i%2 == 0) && (i%N == 0)){
            printf("%d", i);
            break;
        }
    } 

    return 0;
}