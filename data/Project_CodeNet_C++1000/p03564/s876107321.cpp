#include<stdio.h>
int main(){
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);
    int x=1;
    for(int i=0;i<n;i++){
        if(x*2<x+k){
            x*=2;
        }
        else if(x*2>x+k){
            x+=k;
        }
        else{
            x*=2;
        }
    }
    printf("%d",x);
    puts("");
    return 0;
}