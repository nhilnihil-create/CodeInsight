#include <stdio.h>

int main(){
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    int num = 1;
    
    while(n){
        if(num * 2 > num + k){
            break;
        }
        num *= 2;
        n--;
    }
    
    while(n){
        num+=k;
        n--;
    }
    
    printf("%d\n", num);
    
    return 0;
}
