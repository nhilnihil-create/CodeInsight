#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define mem(x,num) memset(x,num,sizeof x)
#define reg(x) for(int i=last[x];i;i=e[i].next)
using namespace std;
inline ll read(){
    ll f=1,x=0;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
//******head by yjjr******
const int maxn=1e6+6,mod=1e9+7;
int n,a[maxn];
ll inv[maxn],fac=1,ans;
int main(){
    n=read();
    rep(i,1,n)a[i]=read();
    inv[1]=1;
    rep(i,2,n)inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    rep(i,1,n)inv[i]=(inv[i]+inv[i-1])%mod;
    rep(i,1,n)ans=(ans+inv[n-i+1]*a[i]%mod+(inv[i]-1)*a[i]%mod)%mod;
    rep(i,2,n)fac=fac*i%mod;
    cout<<(1ll*fac*ans)%mod<<endl;
    return 0;
}