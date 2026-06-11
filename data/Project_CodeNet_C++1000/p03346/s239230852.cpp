// Parasparopagraho Jīvānām

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>

using namespace std ;
using namespace  __gnu_pbds ;
using namespace __gnu_cxx ;

typedef long long ll ;
typedef long double ld ;

typedef pair<int, int> pii ;
typedef pair<ll,ll> pll ;

typedef vector<int> vi ;
typedef vector<ll> vll ;
typedef vector<pii> vpi ;
typedef vector<pll> vpl;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define rep(i,a,b) for (int i = (a); i <= (b); i++)
#define per(i,b,a) for (int i = (b); i >= (a); i--)

#define mp make_pair
#define eb emplace_back
#define pb push_back
#define fi first
#define se second

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

const int mod1 = 1000000007 ;
const int mod2 = 998244353 ;
const ll  infl = 2e18 ;
const int infi = 2e9 ;
const int maxn = 200005 ;
const int block = 500 ;
const int logn = 30 ;
const int alpha = 27 ;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()) ;

/* Careful when using long long
__builtin_clz(int x) {} //: the number of zeros at the beginning of the number
__builtin_ctz(int x) {} //: the number of zeros at the end of the number
__builtin_popcount(int x) {} //: the number of ones in the number
__builtin_parity(int x) {} //: the parity (even or odd) of the number of ones*/
ll modpow(ll a, ll b, int MOD) { ll res = 1 ; while(b) { if(b&1) { res = res*a ; res %= MOD ; } a *= a ; a %= MOD ; b >>= 1 ; } return res%MOD ; }
void upmin(int &a, int b) { if(a < b) { a = b ; } }
void relax(int &a, int b) { if(a > b) { a = b ; } }
ll add(ll a, ll b, int MOD) { a += b ; if(a >= MOD) { a -= MOD ; } return  a ; }
ll sub(ll a, ll b, int MOD) { a -= b ; if(a < 0) { a += MOD ; } return a ; }
ll mul(ll a, ll b, int MOD) { b %= MOD ; a *= b ; a %= MOD ; return a ; }
ll inverse(ll a, ll MOD) { a = modpow(a, MOD - 2, MOD) ; return a ; }
ll lcm(ll a, ll b) { ll ret ; ll g = __gcd(a, b) ; ret = a/g ; ret = ret*b ; return ret ; }

int n ;
int p[maxn] ;
int kaha[maxn] ;
int dp[maxn] ;
int main()
{
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cin >> n ;
    rep(i,0,n-1)
    {
        cin >> p[i] ;
        kaha[p[i]] = i + 1 ;
    }
    rep(i,1,n)
    {
        int abhi = kaha[i] ;
        int pehla = kaha[i-1] ;
        if(abhi > pehla)
        {
            dp[i] = dp[i-1] + 1 ;
        }
        else
        {
            dp[i] = 1 ;
        }
    }
    int res = 0 ;
    rep(i,1,n)
    {
        res = max(res, dp[i]) ;
    }
    res = n - res ;
    cout << res << endl ;
    return 0 ;
}
