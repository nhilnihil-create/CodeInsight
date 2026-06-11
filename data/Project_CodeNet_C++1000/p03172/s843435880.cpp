#include <bits/stdc++.h>
using namespace std;
//#define FOR(i, x, y) for (int i = x; i < y; i++)
//#define FORN(i, x, y) for (int i = x; i <= y; i++)
//#define DEC(i, x, y) for (int i = x; i >= y; i--)
#define scan1(X) scanf("%d", &X)
#define scan2(X, Y) scanf("%d%d", &X, &Y)
#define scan3(X, Y, Z) scanf("%d%d%d", &X, &Y, &Z)
#define scan4(X, Y, Z, W) scanf("%d%d%d%d", &X, &Y, &Z, &W)
#define scanl1(X) scanf("%lld", &X);
#define scanl2(X, Y) scanf("%lld%lld", &X, &Y)
#define scanl3(X, Y, Z) scanf("%lld%lld%lld", &X, &Y, &Z)
#define scanl4(X, Y, Z, W) scanf("%lld%lld%lld%lld", &X, &Y, &Z, &W)
#define print1(X) printf("%d\n", X);
#define print2(X, Y) printf("%d %d\n", X, Y);
#define print3(X, Y, Z) printf("%d %d %d\n", X, Y, Z);
#define print4(X, Y, Z, W) printf("%d %d %d %d\n", X, Y, Z, W);
#define printl1(X) printf("%lld\n", X);
#define printl2(X, Y) printf("%lld %lld\n", X, Y);
#define printl3(X, Y, Z) printf("%lld %lld %lld\n", X, Y, Z);
#define printl4(X, Y, Z, W) printf("%lld %lld %lld %lld\n", X, Y, Z, W);
#define max3(X, Y, Z) max(X, max(Y, Z))
#define max4(X, Y, Z, W) max(max(X, Y), max(Z, W))
#define min3(X, Y, Z) min(X, min(Y, Z))
#define min4(X, Y, Z, W) min(min(X, Y), min(Z, W))
#define popcount(X) __builtin_popcount(X)
#define all(x) x.begin(), x.end()
#define size(X) (int)X.size()
#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define lc(x) 2 * x
#define rc(x) 2 * x + 1
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef pair<ld, ld> pldld;
const long long l_inf = numeric_limits<long long>::max();
const long long l_ninf = numeric_limits<long long>::min();
const int inf = numeric_limits<int>::max();
const int ninf = numeric_limits<int>::min();
const double pi = 1.00 * acos(-1.00);
const double eps = 1e-8;
void cio(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
ll gcd(ll a, ll b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return (a * (b / gcd(a, b))); }
int sq( int x ) {return x * x;}
////////////////////////////////////////////////////////////////////Header
const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;
int n, k;
ll dp[105][maxn];
ll sum[105][maxn];
ll a[105];

ll add ( ll x, ll y ) {
    return ( x + y ) % mod;
}
ll sub ( ll x, ll y ) {
    ll r  = (x - y) % mod;
    if ( r < 0 ) return r + mod;
    return r;
}

int main () {
    scan2(n, k);
    for ( int i = 1; i <= n; i++ ) scan1(a[i]);
    
    dp[0][0] = 1;
    sum[0][0] = 1;
    for ( int i = 1; i <= k; i++ ) {
        sum[0][i] = add(sum[0][i-1], dp[0][i]);
    }
    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 0; j <= k; j++ ) {
            ll x;
            if ( (ll)j - a[i] - 1 < 0 ) x = 0;
            else x = sum[i-1][(ll)j-a[i] -1];
            dp[i][j] = sub(sum[i-1][j], x);
        }
        sum[i][0] = dp[i][0];
        for ( int j = 1; j <= k; j++ ) sum[i][j] = add(sum[i][j-1], dp[i][j]);
    }
    printl1(dp[n][k]);
}