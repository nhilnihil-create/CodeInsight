#include<bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;
inline int read(){
    int ans=0;
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))ans=(ans<<3)+(ans<<1)+(ch^48),ch=getchar();
    return ans;
}
int n;
ll ans=1e18,X,x[N],sum[N];
int main(){
    n=read(),X=read();
    for(int i=1;i<=n;++i)sum[i]=(x[i]=read())+sum[i-1];
    for(int k=1;k<=n;++k){
        ll tmp=0;
        for(int j=1,l=0,r=n;r&&tmp+k*X<ans;++j,r=l-1){
            l=max(r-k+1,1);
            tmp+=(j==1?5:(j<<1)+1)*(sum[r]-sum[l-1]);
        }
        ans=min(ans,tmp+k*X);
    }
    printf("%lld",ans+n*X);
    return 0;
}
