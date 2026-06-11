#include <iostream>
#include <cstring>
#define For(i,x,y) for(register int i=(x); i<=(y); i++)
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll qpow(ll a, ll n)
{
    ll ans=1;
    while(n)
    {
        if(n&1)ans=(ans%mod)*(a%mod)%mod;
        a=a%mod*(a%mod)%mod;
        n>>=1;
    }
    return ans;
}
const int maxn=1e5+10;
ll inv[maxn],a[maxn];
int main()
{
    ll ans=0,cnt=1;
    int n;
    cin>>n;
    For(i,1,n)cin>>a[i],cnt=cnt%mod*(i%mod)%mod;//先计算方案数
    For(i,1,n)inv[i]=(qpow(i,mod-2)+inv[i-1])%mod;
    For(i,1,n)ans+=(a[i]%mod)*(inv[i]+inv[n-i+1]-1)%mod;//这里减1，是减去自身的重复。
    cout<<cnt*(ans%mod)%mod<<endl;
    return 0;
}
