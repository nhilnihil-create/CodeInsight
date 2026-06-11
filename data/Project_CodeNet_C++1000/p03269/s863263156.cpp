#include<bits/stdc++.h>
using namespace std;
const int LOG=20;
int l,n,m,u[1005],v[1005],w[1005];
int main(){
    scanf("%d",&l);
    for(int i=0;i<=LOG;i++)
        if((1<<i)>l){
            n=i;
            break;
        }
    for(int i=1;i<n;i++){
        u[++m]=i,v[m]=i+1,w[m]=0;
        u[++m]=i,v[m]=i+1,w[m]=1<<(i-1);
    }
    int t=1<<(n-1);
    l-=t;
    for(int i=n-1;i;i--)
        if((1<<(i-1))<=l){
            u[++m]=i,v[m]=n,w[m]=t;
            t+=1<<(i-1);
            l-=1<<(i-1);
        }
    printf("%d %d\n",n,m);
    for(int i=1;i<=m;i++)
        printf("%d %d %d\n",u[i],v[i],w[i]);
    return 0;
}