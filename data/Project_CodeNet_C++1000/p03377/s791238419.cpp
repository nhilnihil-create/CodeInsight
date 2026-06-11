#include <iostream>

int main(){
    int A,B,X;
    
    scanf("%d %d %d", &A, &B, &X);

    if(A == X){
        printf("YES");
    }else if(A > X){
        printf("NO");
    }else if(A < X){
        if((A + B) >= X){
            printf("YES");
        }else{
            printf("NO");
        }
    }

    return 0;
}