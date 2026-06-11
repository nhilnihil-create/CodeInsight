#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using Graph = vector<vector<bool>>;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<pii> xy(N);
    for (int i = 0; i < N; ++i)
        cin >> xy[i].first >> xy[i].second;
    sort(xy.begin(), xy.end());

    ll ans = LLONG_MAX;
    for (int l = 0; l < N; ++l) {
        for (int t = l; t < N; ++t) {
            for (int b = l; b < N; ++b) {
                if (xy[t].second < xy[b].second)
                    continue;
                int cnt = 0, minr = INT_MAX;
                for (int r = l; r < N; ++r) {
                    if (xy[r].second >= xy[b].second && xy[r].second <= xy[t].second)
                        cnt++;
                    minr = xy[r].first;
                    if (cnt >= K)
                        break;
                }
                if (cnt >= K)
                    ans = min(ans, (ll)(minr - xy[l].first) * (xy[t].second - xy[b].second));
            }
        }
    }

    cout << ans << endl;
    return 0;
}
