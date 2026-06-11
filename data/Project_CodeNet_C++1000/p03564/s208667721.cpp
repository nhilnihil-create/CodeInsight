#include <stdio.h>

int main (){
    int n,k;
    scanf("%d", &n);
    scanf("%d", &k);
    int ans=1;

    for(int i=0;i<n;i++){
        if(ans<k){
            ans*=2;
        } else {
            ans+=k;
        }
    }

    /* int i = 0;
    while(i<n){
        if(ans<k){
            ans*=2;
        } else {
            ans+=k;
        }
        ++i;
    }
    */
    printf("%d\n", ans);
}