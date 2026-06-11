#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<pair<ll, ll>> v(N);
    for(int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;

    ll ans = longinf;
    for(int a = 0; a < N; a++) {
        for(int b = 0; b < N; b++) {
            for(int c = 0; c < N; c++) {
                for(int d = 0; d < N; d++) {
                    ll left = min(v[a].first, min(v[b].first, min(v[c].first, v[d].first)));
                    ll right = max(v[a].first, max(v[b].first, max(v[c].first, v[d].first)));
                    ll under = min(v[a].second, min(v[b].second, min(v[c].second, v[d].second)));
                    ll top = max(v[a].second, max(v[b].second, max(v[c].second, v[d].second)));

                    int cnt = 0;
                    for(int i = 0; i < N; i++) {
                        if(left <= v[i].first && v[i].first <= right && under <= v[i].second && v[i].second <= top) cnt++;
                    }
                    if(cnt >= K && (right - left) * (top - under) != 0) ans = min(ans, (right - left) * (top - under));
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
