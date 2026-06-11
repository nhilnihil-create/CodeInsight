#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define forab(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define fst first
#define snd second
 
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using vvi = vector<vi>;
 
#define FILE_NAME "a"
 
string s;
int k;
 
bool read() {
    if (!(cin >> s >> k)) {
        return 0;
    }
    return 1;
}

void remax (int &x, int y)
{
    x = max(x, y);
}

const int N = 310;
const int inf = (int)1e9;
int dp[N][N][N];
 
void solve() {
    fill_n(&dp[0][0][0], N * N * N, -inf);
    
    const int n = sz(s);

    forn (r, n + 1) ford (l, r + 1) forn (ch, k + 1)
    {
        int &cur = dp[l][r][ch];

        const int len = r - l;
        
        if (len <= 1)
        {
            cur = len;
            continue;
        }
            
        remax(cur, dp[l][r - 1][ch]);
        remax(cur, dp[l + 1][r][ch]);
        if (s[l] == s[r - 1])
            remax(cur, dp[l + 1][r - 1][ch] + 2);
        else if (ch)
            remax(cur, dp[l + 1][r - 1][ch - 1] + 2);
    }

    int ans = 0;
    forn (ch, k + 1)
       remax(ans, dp[0][n][k]);
    cout << ans << endl; 
}
 
int main() {
#ifdef LOCAL
    freopen(FILE_NAME ".in", "r", stdin);
//    freopen(FILE_NAME ".out", "w", stdout);
#endif
 
    while (read()) {
        solve();
    }
 
    return 0;
}
