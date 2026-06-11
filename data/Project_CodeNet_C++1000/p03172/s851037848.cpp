#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long int ll;
#define MOD 1000000007
//#define MOD 998244353
#define N 100005
#define INF 1e18
#include <ctime>
#define rep(i, x, n) for (ll i = x; i < n; i++)
#define rev(i, n, x) for (ll i = n; i > x; i--)
#define all(c) (c).begin(), (c).end()
#define int long long int
#ifdef mishra
#define debug(x) cout << " >> " << #x << ": " << x << " ";
#define debugend() cout << endl;
#define print_time() cout << setprecision(6) << "time: " << 1000 * ((clock() - start) / (double)CLOCKS_PER_SEC) << " ms\n";
#else
#define endl "\n"
#define debug(x) ;
#define debugend() ;
#define print_time() ;
#endif

clock_t start;
void FAST(int argc)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    start = clock();
    if (argc == 2)
        freopen("std.in", "r", stdin);
}

/*vector<int> v;
void sieve()
{
    v.pb(2);
    for (int i = 3; i < N; i += 2)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (i % v[j] == 0)
                break;
            if (v[j] * v[j] > i)
            {
                v.pb(i);
                break;
            }
        }
    }
}
/*
void prime_factor(int x, vector<int> &r)
{
    int sqrt_x = sqrt(x);

    for (int i : v)
    {
        if (i > sqrt_x)
            break;

        if (x % i == 0)
            r.pb(i);

        while (x % i == 0)
        {
            x /= i;
        }
    }

    if (x >= 2)
        r.pb(x);
}
*/
/*
int power(int x, int y)
{
    int res = 1;
    x = x % MOD;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}
*/
/*
inline void dfs(int curr, int prev)
{

    for (auto i : a[curr])
        if (i != prev)
            dfs(i, curr);
}
*/
/*
int multi(int a, int b)
{
    return ((a * b) % MOD);
}
*/
//---------------------CODE STARTS HERE---------------------
string ny[2] = {"NO", "YES"};
int n, x, a[N], b[N], ck = 0;

signed main(char argc, char *argv[]) // on my IDE argc is always = 2
{
    FAST(argc);

    int testcase = 1;
    // cin >> testcase;

    while (testcase--)
    {
        int k;
        cin >> n >> k;
        rep(i, 0, n)
                cin >>
            a[i];
        sort(a, a + n, greater<int>());
        int dp[n][k + 1];
        memset(dp, 0, sizeof(dp));
        int s = 0;
        rev(i, n - 1, -1)
        {
            dp[i][0] = 1;
            rep(j, 1, k + 1)
            {
                if (i == n - 1 && j <= a[i])
                    dp[i][j] = 1;
                else if (i != n - 1)
                {
                    if (j > s + a[i])
                        break;
                    dp[i][j] = dp[i][j - 1] + dp[i + 1][j];
                    if (j - a[i] > 0)
                        dp[i][j] -= dp[i + 1][j - a[i] - 1];
                    // pref[j - a[i] - 1];
                    dp[i][j] = (dp[i][j] + MOD) % MOD;
                }
            }
            s += a[i];
        }
        cout << dp[0][k] << endl;
        //--------??--------CLEAR VECTORS--------??--------
    }

    //v.clear();
    print_time();
    return 0;
}