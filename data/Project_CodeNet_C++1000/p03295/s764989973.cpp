#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, b, a) for (int i = a - 1; i >= b; i--)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    int n, m;
    cin >> n >> m;
    pint p[m];
    // 終端でsort
    rep (i, 0, m) cin >> p[i].second >> p[i].first;
    sort (p, p + m);
    int ans = 0, end = 0;
    // 始まる時間が最後の終わる時間より遅ければ＋１する
    rep (i, 0, m) {
        if (p[i].second >= end) {
            end = p[i].first;
            ans++;
        }
    }
    cout << ans << "\n";
}
