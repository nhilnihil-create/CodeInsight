#include <iostream>

int main(){
    int A,B;
    scanf("%d %d", &A, &B);
    
    if(A > 8 || B > 8){
        printf(":(");
    }else if ((A >= 0) && (B >= 0)){
        printf("Yay!");
    }else{
        printf(":(");
    }
    return 0;
}