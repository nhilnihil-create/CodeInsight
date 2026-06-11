#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

signed main() {
    int n, k;
    cin >> n >> k;
    int v[n];
    rep (i, 0, n) cin >> v[i];
    int ans = 0;
    rep (i, 0, min (n, k) + 1) {
        for (int j = 0; i + j <= min (n, k); j++) {
            int sum = 0;
            vector<int> vec;
            rep (l, 0, i) {
                vec.push_back (v[l]);
                sum += v[l];
            }
            rep (l, 0, j) {
                vec.push_back (v[n - l - 1]);
                sum += v[n - 1 - l];
            }
            sort (vec.begin(), vec.end());
            rep (l, 0, min (k - i - j, (int)vec.size())) {
                if (vec[l] < 0) sum -= vec[l];
            }
            ans = max (ans, sum);
        }
    }
    cout << ans << "\n";
}