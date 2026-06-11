#include <stdio.h>

int main(){
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    if (a > b && a > c){
        printf("%d\n", (b*c)/2);
    }
    else if (b > a && b > c){
        printf("%d\n", (a*c)/2);
    }
    else {
        printf("%d\n", (a*b)/2);
    }





return 0;
}
