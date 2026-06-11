#include <bits/stdc++.h>
using namespace std;
#define FOR(i, x, y) for (int i = x; i < y; i++)
#define FORN(i, x, y) for (int i = x; i <= y; i++)
#define DEC(i, x, y) for (int i = x; i >= y; i--)
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
const int maxn = 305;
double dp[maxn][maxn][maxn];
int n;
int a[4];


double getdp ( int p, int q, int r ) {
    if ( p==0 && q==0 && r==0 ) return 0;
    double &ret = dp[p][q][r];
    if ( ret > -0.9 ) return dp[p][q][r];
    ret = 0;
    ret += (double)( n - p - q - r ) / ( p + q + r);
    if ( p ) ret += (getdp(p-1, q, r) + 1) * (double) p/(p+q+r);
    if ( q ) ret += (getdp(p+1, q-1, r) + 1) * (double) q/(p+q+r);
    if ( r ) ret += (getdp(p, q+1, r-1) + 1) * (double) r/(p+q+r);
    return ret;
}

int main () {
    scan1(n);
    FORN(i, 1, n) {
        int x; scan1(x);
        a[x]++;
    }
    memset(dp, -1, sizeof(dp));
    printf("%.12lf\n", getdp(a[1], a[2], a[3]));
}