#include <iostream>
using namespace std;

#define ll long long
#define pb push_back
#define ins insert
#define mp make_pair
#define pii pair<int, int>
#define pil pair<int, ll>
#define pib pair<int, bool>
#define SET(a, c) memset(a, c, sizeof(a))
#define MOD 1000000007
#define enld endl
#define endl "\n"
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define FOUND(u, val) u.find(val) != u.end()
#define max_self(a, b) a = max(a, b);

#include <string>
#include <vector>
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
//#include <algorithm>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
//#include <cmath>
//#include <cstring>
//#include <sstream>
//#include <stack>
//#include <queue>
int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    char grid[n][m];
    for (int tr = 0; tr < n; tr++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[tr][j];
        }
    }

    ll dp[n + 1][m + 1];
    if (grid[n - 1][m - 1] == '#') {
        cout << 0;
        return 0;
    }
    for (int i = 0; i <= n; i++) dp[i][m] = 0;
    for (int j = 0; j <= m; j++) dp[n][j] = 0;

    dp[n - 1][m - 1] = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (j == m - 1 && i == n - 1) continue;
            if (grid[i][j] == '#') {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = (dp[i + 1][j] + dp[i][j + 1]) % MOD;
        }
    }

    cout << dp[0][0];
}