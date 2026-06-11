#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=100000000000000000;

ll mpow(ll x, ll n){
ll ans = 1;
while(n != 0){
if(n&1) ans = ans*x % mod;
x = x*x % mod;
n = n >> 1;
}
return ans;
}


int main() {
    int n;
    ll a,b,c;
    cin >> n >> a >> b >> c;
    ll ans=0;
    vector<ll> kj(n+1),gj(n+1);
    kj[0]=1;gj[0]=1;
    rep(i,n){
        (kj[i+1]=kj[i]*(i+1))%=mod;
        (gj[i+1]=gj[i]*mpow(i+1,mod-2))%=mod;
    }
    ll k=kj[n];
    vector<ll> co(n+1);
    rep(i,n+1){
        co[i]=((k*gj[n-i])%mod)*gj[i]%mod;
    }
    rep(i,n+1){
        ll t=c-i*b;
        ll u=t/a;
        if (t%a==0 && u>=0 && u<n+1){
            (ans+=co[u]*co[i]%mod)%=mod;
        }
    }
    cout << ans << endl;
}
