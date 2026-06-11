#include<bits/stdc++.h>
using namespace std;
const int N=5005;
long long s[N],p[N],f[N];
int n,A,B;
int main(){
    //freopen("1.out","w",stdout);
    //freopen("1.in","r",stdin);
    memset(f,23,sizeof(f));
    scanf("%d%d%d",&n,&A,&B),f[0]=0;
    for(int i=1,x;i<=n;i++){
        scanf("%d",&x);
        for(int j=0;j<=n;j++)
            if(j)   p[j]=min(p[j-1],f[j]);
            else    p[j]=f[j];
        for(int j=0;j<=x;j++)   f[j]+=A;
        for(int j=x+1;j<=n;j++) f[j]+=B;
        f[x]=min(f[x],p[x]);
    }
    long long ans=f[n+1];
    for(int i=0;i<=n;i++)   ans=min(ans,f[i]);
    printf("%lld\n",ans);
    return 0;
}