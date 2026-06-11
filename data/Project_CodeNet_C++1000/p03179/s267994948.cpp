#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
 
// Remove GCC optimizer for codechef
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
using namespace __gnu_pbds;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define endl "\n"
#define int long long
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
const int INF = 1e16;
const double PI = acos(-1);
const int N = 1e6 + 7;
int mod = 1e9 + 7;

const int maxn = 3e3 + 7;
int dp[maxn][maxn];

int32_t main()
{
    IOS;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    string s;
    cin >> s;
    dp[1][1] = 1;
    vector<int> pref(n+1, 0);
    for(int i = 0; i < s.size(); i++)
    {
        int k = i + 2;
        for(int j = 1; j <= n; j++)
        {
            pref[j] = pref[j-1] + dp[k-1][j];
            pref[j] %= mod;
        }
        for(int j = 1; j <= k; j++)
        {
            int l, r;
            if(s[i] == '<')
                l = 1, r = j - 1;
            else
                l = j, r = k;
            if(l <= r)
                dp[k][j] = (pref[r] - pref[l-1] + mod) % mod;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans += dp[n][i], ans %= mod;
    cout << ans << endl;
    return 0;
}