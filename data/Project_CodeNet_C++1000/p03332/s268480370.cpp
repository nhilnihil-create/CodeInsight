#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<tuple>
#include<list>
#include<unordered_map>
#include <random>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pp pair<pair<ll, ll>,pair<ll, ll>>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define LB(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define UB(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
#define ERASE(v) v.erase(unique(v.begin(),v.end()),v.end())
// #define int ll
using namespace std;
const ll INF = (1 << 30 ) - 1;
const ll LLINF = (1LL << 60LL);
const ll MOD = 1000000007;
const ll mod = 998244353;
const ll MAX = 510000;
const double pi = acos(-1);
const double eps = 1e-9;
ll dx[4] ={1,0,-1,0} , dy[4] ={0,1,0,-1};


ll fac[MAX], finv[MAX], inv[MAX];

void COMinit(ll MOD) {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

ll COM(ll n, ll k, ll MOD){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    COMinit(mod);
    ull n,a,b,k;
    ll ans=0;
    cin>>n>>a>>b>>k;
    rep(i,n+1){
        if((k-i*a)%b!=0) continue;
        ll j=(k-i*a)/b;
        ans+=COM(n,i,mod)*COM(n,j,mod)%mod;
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}
