#include <bits/stdc++.h>                                          // This will work only for g++ compiler.
#define for0(i, n) for (int i = 0; i < (int)(n); ++i)             // 0 based indexing
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)            // 1 based indexing
#define forab(i, l, r) for (int i = (int)(l); i <= (int)(r); ++i) // closed interver from l to r r inclusive
#define forr0(i, n) for (int i = (int)(n)-1; i >= 0; --i)         // reverse 0 based.
#define forr1(i, n) for (int i = (int)(n); i >= 1; --i)           // reverse 1 based
#define pb push_back
#define fi first
#define se second
#define __builtin_popcount(x) ones(x)
#define __builtin_popcountl(x) onesl(x)
#define __builtin_popcountll(x) onesll(x) // to be used with algorithms that processes a container Eg: find(all(c
#define all(x) (x).begin(), (x).end()     //Forward traversal
#define rall(x) (x).rbegin, (x).rend()    //reverse traversal
#define tr(c, i) for (__typeof__((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define sz(a) int((a).size())
#define Fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define InputOuput                    \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
const ll linf = 1e18L + 5;
const int inf = 1e9 + 5;
const int mod = 1e9 + 7;

int md(int x)
{
    return ((x % mod) + mod) % mod;
}
int main()
{
    //InputOuput;
    Fast;
    //setprecision(2);
    int n ; cin >> n;
    vector<double> prob(n+1);
    for1(i,n ) cin >> prob[i];
    vector<vector<double > > dp(n+1, vector<double>(n+1, (double)1));
    for1(i,n){
        forab(heads, 0, i){
            double tails =
            dp[i][heads] = ( (heads == i) ?(double) 0: (1-prob[i])*dp[i-1][heads]) + ( (heads == 0)?(double)0 : prob[i]*dp[i-1][heads-1]);
        }
    }
    double ans = (double)0;
    forab(i, (n+1)/2 , n){
        ans += dp[n][i];
    }
    cout << setprecision(10)<< ans << '\n';
    return 0;
}