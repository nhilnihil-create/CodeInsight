#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define int long long
#define ff first
#define ss second
#define fill(x, v) memset(x, v, sizeof(x))
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define ios std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args)
{
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
/*
std::cout << std::setprecision(9) << f << '\n';//3.141590000;
map<char,int>::reverse_iterator rit;
for(rit = mp.rbegin(); rit!=mp.rend(); rit++)
*/
int n, m, k, t, mod = 1e9 + 7;
int h[200005];
int a[200005];
int dp[200005]; // dp[i] = max beauty obtained  till height i;
int tree[200005];
int32_t main()
{
    ios;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int pre_max = INT_MIN;

        // max dp[i] from i = 0, h[i]-1;
        int x = h[i] - 1;
        ++x;
        while (x)
            pre_max = max(pre_max, tree[x]), x -= x & (-x);

        dp[h[i]] = max(dp[h[i]], pre_max + a[i]);

        //update fenwk tree
        x = h[i];
        ++x;
        while (x <= n)
            tree[x] = max(tree[x], dp[h[i]]), x += x & (-x);

        //update ans
        ans = max(ans, dp[h[i]]);
    }

    cout << ans << endl;
}
