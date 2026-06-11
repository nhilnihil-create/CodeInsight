#include<stdio.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
int L,b[50],bt,n,x[90],y[90],z[90],m,now;//!!! x[50] y[50] z[50]
int main(){
    scanf("%d",&L);
    while (L){
        b[++bt]=L&1;
        L>>=1;
    }
    n=1;now=1;
    fd(i,bt-1,1){
        now<<=1;
        fo(j,1,m) z[j]<<=1;
        x[++m]=++n;y[m]=n-1;z[m]=0;
        x[++m]=n;y[m]=n-1;z[m]=1;
        if (b[i]){
            x[++m]=n;y[m]=1;z[m]=now;
            now^=1;
        }
    }
    printf("%d %d\n",n,m);
    fo(i,1,m) printf("%d %d %d\n",n-x[i]+1,n-y[i]+1,z[i]);
    return 0;
}
