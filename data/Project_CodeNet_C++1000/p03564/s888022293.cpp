#include <stdio.h>

int main() {
    int n, k;
    scanf("%d%d", &n,&k);
    int jwb = 1;
    for (int i=0; i<n; i++){
        if (jwb*2 < jwb+k){
            jwb*=2;
        }
        else{
            jwb+=k;
        }
    }
    printf("%d\n", jwb);
    return 0;
}