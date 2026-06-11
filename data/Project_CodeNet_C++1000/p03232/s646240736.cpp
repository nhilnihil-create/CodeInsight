#include<bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;i++)
#define per(i,l,r) for (int i=l;i>=r;i--)
typedef long long ll;
using namespace std;
const int maxn=100500;
const ll mm=1e9+7;
int n,m;
ll fac[maxn],inv[maxn],r[maxn],a[maxn],sum[maxn];
ll ans;
ll Pow(ll x,ll y){
    ll ans=1;
    while (y){
        if (y&1) ans=ans*x%mm;
        x=x*x%mm;
        y/=2;
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    int N=100000;
    fac[0]=1; rep(i,1,N) fac[i]=fac[i-1]*i%mm;
    inv[N]=Pow(fac[N],mm-2); per(i,N,1) inv[i-1]=inv[i]*i%mm;
    r[0]=1; per(i,N,1) r[i]=inv[i]*fac[i-1]%mm;
    rep(i,1,n) scanf("%lld",&a[i]);
    rep(i,1,n) sum[i]=(sum[i-1]+fac[n]*r[i]%mm)%mm;
    ll ans=0;
    rep(i,1,n) (ans+=(sum[i]+sum[n-i+1]-fac[n]+mm)%mm*a[i]%mm)%=mm;
    cout<<ans<<endl;
    return 0;
}