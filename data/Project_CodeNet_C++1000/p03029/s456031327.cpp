#include <stdio.h>

int main(){
    int a,p;
    scanf("%d %d", &a, &p);
    
    int total = (a*3) + p;
    int hasil = total / 2;
    printf("%d", hasil);
    
    return 0;
}