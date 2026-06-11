#include<cstdio>

int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int a = n/2;
    int b = n-a;
    if(k<=a || k<=b) printf("YES\n");
    else printf("NO\n");    
    return 0;
}
