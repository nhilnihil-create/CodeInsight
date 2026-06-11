#include <iostream>

int main(){
    int A,B, Max = 0;
    scanf("%d %d", &A, &B);
    Max = A + B;
    if((A - B) > Max){
        Max = A - B;
    }
    if((A * B) > Max){
        Max = A * B;
    }
    printf("%d", Max);

    return 0;
}