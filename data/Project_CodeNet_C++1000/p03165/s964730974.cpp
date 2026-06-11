#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define lc 2 * v
#define rc 2 * v + 1
#define mid (s + e) / 2
#define ll long long
#define int long long
#define ld long double
#define pii pair <int , int>
#define pll pair <long long , long long>
#define FAST ios::sync_with_stdio(false);cin.tie(0);
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

const int maxn = 3000 + 10 , N = 1e5 + 5 , SQ = 600 , base = 1999 , mod = 1e9 + 7 , INF = 1e18 , lg = 17;

int dp[maxn][maxn] , c1 , c2;
pii par[maxn][maxn];
string s , t;

int32_t main() {
    FAST
    cin >> s >> t;
    c1 = s.size() , c2 = t.size();

    for (int i = 1; i <= c1; ++i) {
        for (int j = 1; j <= c2; ++j) {
            if(s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                par[i][j] =  {i - 1 , j - 1};
            }
            if(dp[i - 1][j] > dp[i][j]) {
                dp[i][j] = dp[i - 1][j];
                par[i][j] = {i - 1 , j};
            }
            if(dp[i][j - 1] > dp[i][j]) {
                dp[i][j] = dp[i][j - 1];
                par[i][j] = {i , j - 1};
            }
        }
    }

    string ans = "";

    while(c1 && c2) {
        int x = par[c1][c2].F , y = par[c1][c2].S;
        if(s[c1 - 1] == t[c2 - 1]) {
            ans += s[c1 - 1];
        }
        c1 = x , c2 = y;
    }

    reverse(ans.begin() , ans.end());
    cout << ans << '\n';
 }
