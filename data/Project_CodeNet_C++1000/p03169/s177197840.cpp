#include <bits/stdc++.h>
const int mod = 1000000007;
const int modx = 998244353;
#define ll long long
#define readi(x) scanf("%d", &x)
#define reads(x) scanf("%s", x)
#define readl(x) scanf("%I64d", &x)
#define rep(i, n) for (i = 0; i < n; i++)
#define rep1(i, a, b) for (i = a; i < b; i++)
#define rep2(i, a, b) for (i = b; i >= a; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define bpc(x) __builtin_popcount(x)
#define pll pair<ll, ll>
#define pii pair<int, int>
#define pdd pair<double, double>
#define pic pair<int, char>
#define ddouble long double
#define PI 3.1415926535
#define endl "\n"
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vi>
#define all(x) x.begin(), x.end()
#define prod(x, y) ((x % mod) * (y % mod)) % mod
#define add(x, y) ((x % mod) + (y % mod)) % mod
#define ub(a, b) upper_bound(all(a), b)
#define lb(a, b) lower_bound(all(a), b)
#define pqs priority_queue<int, vector<int>, greater<int>>
#define pqb priority_queue<int>
#define mii map<int, int>
#define mll map<ll, ll>
using namespace std;
//using namespace __gnu_pbds;
/*ll power(ll x, ll y)
{
    ll r = 1;
    x = x % mod;
    while (y > 0)
    {
        if (y & 1)
            r = (r*x) % mod;

        y = y>>1;
        x = (x*x) % mod;
    }
    return r;
}*/
const int N = 300;
int n;
ddouble dp[N + 1][N + 1][N + 1] = {}, vis[N + 1][N + 1][N + 1] = {};
ddouble rec(int x, int y, int z)
{
    if (x < 0 || y < 0 || z < 0)
        return 0;
    if (x == 0 && y == 0 && z == 0)
        return 0;
    if (vis[x][y][z])
        return dp[x][y][z];
    vis[x][y][z] = 1;
    ddouble ans = x * rec(x - 1, y, z) * 1.0 + y * rec(x + 1, y - 1, z) * 1.0 + 1.0 * z * rec(x, y + 1, z - 1) + n * 1.0;
    ans = ans / (x + y + z) * 1.0;
    dp[x][y][z] = ans;
    return ans;
}
void thunder()
{
    cin >> n;
    int i;
    int x = 0, y = 0, z = 0;
    rep(i, n)
    {
        int p;
        cin >> p;
        if (p == 1)
            x++;
        else if (p == 2)
            y++;
        else
            z++;
    }
    ddouble ans = rec(x, y, z);
    cout << fixed << setprecision(9) << ans << endl;
    return;
}
int main()
{
    /*#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif*/
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll q = 1;
    //cin >> t;
    while (q--)
        thunder();
}
