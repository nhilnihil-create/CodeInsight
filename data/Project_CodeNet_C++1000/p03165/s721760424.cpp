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
const int maxn = 3009;
string s, t;
int dp[maxn][maxn];
 
int main () {
    cio();
    cin>>s>>t;
    int n = size(s), m = size(t);
    s = '0' + s;
    t = '0' + t;
    FORN(i, 1, n) {
        FORN(j, 1, m) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if ( s[i] == t[j] ) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
        }
    }
    string ans = "";
    int i = n, j = m;
    while ( i >= 1 && j >= 1 ) {
        if ( s[i] == t[j] &&  dp[i][j] == dp[i-1][j-1] + 1 ) {
            if ( i == 1 ) ans += s[i];
            else if ( j == 1 ) ans += t[j];
            else ans += s[i];
 
            i = i - 1;
            j = j - 1;
        }
        else if ( dp[i][j] == dp[i][j-1] ) {
            j = j - 1;
        }
        else {
            i = i - 1;
        }
    }
    reverse(all(ans));
    cout<<ans<<endl;
}