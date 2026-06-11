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

ll dp[405][405];
//dp[i][j] will be the minimum total cost of combining [i,j] into one vertex

ll sum(int L, int R, ll ar[]) {
    ll s = 0;
    for (int i = L; i <= R; i++) {
        s += ar[i];
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    ll ar[n];
    for (ll &x : ar) cin >> x;
    // for (int i = 0; i < n; i++) cin >> ar[i];

    /* 
4
10 20 30 40
 */

    for (int L = n - 1; L >= 0; --L) {
        for (int R = L; R < n; ++R) {
            if (L == R) {
                dp[L][R] = 0;
            } else {
                dp[L][R] = 1e18;
                for (int i = L; i < R; i++) {
                    dp[L][R] = min(dp[L][R], dp[L][i] + dp[i + 1][R] + sum(L, R, ar));
                }
            }
        }
    }

    cout << dp[0][n - 1];
}