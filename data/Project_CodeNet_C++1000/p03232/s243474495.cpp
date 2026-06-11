//#include <ext/pb_ds/hash_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/rope>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <ctime>

#define X first
#define Y second
#define ls rt<<1
#define rs rt<<1|1
#define getmid ((l+r)>>1)
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define lowbit(x) ((x)&-(x))
#define sz(a) ((int)a.size())
#define ALL(x) x.begin(),x.end()
#define mst(x,a) memset(x, a, sizeof(x))
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep1(i,n) for(int i=1; i<=(n); i++)
using namespace std;
#ifdef LOCAL
#define dbg(args...) cout << #args << " -> ", err(args);
void err(){ cout << endl; }
template<typename T, typename... Args>
void err(T a, Args... args){ cout << a << ' '; err(args...); }
#else
#define dbg(a)
#endif // LOCAL

//using namespace __gnu_cxx;
//using namespace __gnu_pbds;
typedef double db;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
typedef pair<int,int> pii;
typedef pair<db,db> pdd;

const int N = 1e5 + 10;
const int M = 2e5 + 10;
const int maxn = 1e6 + 10;
const int mod = (int)1e9+7;
const db eps = 1e-10;
const db pi = acos(-1.0);

int n;
ll a[N];
ll dp[N];
ll fac[N];
ll inv[N];

ll qpow(ll a, ll b){
    ll res = 1;
    for(a%=mod; b; b>>=1){
        if(b&1) res = res*a%mod;
        a = a*a%mod;
    }
    return res;
}

ll C(int n, int m){
    return fac[n]*inv[n-m]%mod*inv[m]%mod;
}

void init(){
    inv[0] = fac[0] = 1;
    for(int i=1; i<N; i++){
        fac[i] = fac[i-1]*i%mod;
        inv[i] = qpow(fac[i], mod-2);
    }
}

int main(){
#ifdef LOCAL
    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
#endif //LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    cin>>n;
    ll sum = 0;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        sum = (sum + a[i])%mod;
    }
    ll ans = 0;
    for(int i=2; i<=n; i++){
        ll t = fac[i-1]*fac[n-i]%mod*C(n, i)%mod;
        dp[i] = (dp[i-1] + t)%mod;
        ans = (ans + dp[i]*a[i])%mod;
    }
    dp[n] = 0;
    for(int i=n-1; i; i--){
        ll t = fac[n-i]*fac[i-1]%mod*C(n, n-i+1)%mod;
        dp[i] = (dp[i+1] + t)%mod;
        ans = (ans + dp[i]*a[i])%mod;
    }
    ans = (ans + sum*fac[n])%mod;
    cout<<ans<<'\n';

    return 0;
}
