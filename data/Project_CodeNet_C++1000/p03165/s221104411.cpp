#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define pb push_back
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define endl "\n"
#define pii pair<int,int>
#define mii map<int,int>
#define int long long int
#define fbo find_by_order
#define ook order_of_key
#define in insert
#define F first
#define S second
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a) for(auto ws: a)cout<<ws<<" "; cout<<endl
#define print1(a,b) for(int ws=0;ws<b;ws++) {cout<<a[ws]<<" ";} cout<<endl
#define all(a) a.begin(), a.end()
#define si set<int>
#define print2(a) for(auto ws: a)cout<<"("<<ws.F<<","<<ws.S<<") "; cout<<endl

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}
int cache[3001][3001];
// int dp(string s, string t, int i, int j)
// {
//     if (i == s.size())return 0;
//     if (j == t.size())return 0;
//     int &ans = cache[i + 1][j + 1];
//     if (ans != -1)return ans;
//     if (s[i] == t[j])
//     {
//         return ans = 1 + dp(s, t, i + 1, j + 1);
//     }
//     else
//     {
//         return ans = max(dp(s, t, i + 1, j), dp(s, t, i, j + 1));
//     }
// }
void dp(string s, string t)
{
    int n = s.size();
    int m = t.size();
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)dp[i][j] = 0;
            else if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string ans;
    for (int j = t.size(), i = s.size(); j >= 1  && i >= 1;)
    {
        if (s[i - 1] == t[j - 1])
        {
            ans += s[i - 1];
            i--, j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])i--;
        else j--;
    }
    reverse(all(ans));
    cout << ans << endl;

}
void solve()
{
    memset(cache, -1, sizeof(cache));
    string s, t;
    cin >> s >> t;
    dp(s, t);


}
int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
#endif
    cout << setprecision(9) << fixed;
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}