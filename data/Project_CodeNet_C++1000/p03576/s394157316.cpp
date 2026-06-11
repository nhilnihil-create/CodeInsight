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
    for (int t = 0; t < N; ++t) {
        for (int b = 0; b < N; ++b) {
            if (xy[t].second <= xy[b].second)
                continue;
            int cnt = 0;
            for (int l = 0, r = 0; l < N; ++l) {
                while (r < N && cnt < K) {
                    if (xy[r].second >= xy[b].second && xy[r].second <= xy[t].second)
                        cnt++;
                    r++;
                }
                if (cnt < K)
                    break;
                ans = min(ans, (ll)(xy[r - 1].first - xy[l].first) * (xy[t].second - xy[b].second));
                if (xy[l].second >= xy[b].second && xy[l].second <= xy[t].second)
                    cnt--;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
