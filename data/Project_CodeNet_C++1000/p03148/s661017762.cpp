#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll INF = ll(1e18) + 5;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<P> td(N);
    rep(i, N) {
        cin >> td[i].second >> td[i].first;
    }

    sort(td.rbegin(), td.rend());

    vector<ll> first, second;
    unordered_map<ll, ll> mp;
    rep(i, N) {
        if (mp.find(td[i].second) == mp.end()) {
            mp[td[i].second]++;
            first.push_back(td[i].first);
        } else {
            second.push_back(td[i].first);
        }
    }
    vector<ll> fSum(K + 1, 0), sSum(K + 1, 0);
    rep(i, K) {
        fSum[i + 1] = fSum[i];
        if (i < first.size()) {
            fSum[i + 1] += first[i];
        }
        sSum[i + 1] = sSum[i];
        if (i < second.size()) {
            sSum[i + 1] += second[i];
        }
    }
    ll ans = 0;
    ll e = min(K, (ll)first.size());
    for (ll i = 1ll; i <= e; i++) {
        // cerr << "i= " << i << "i * i + fSum[i] + sSum[K - i]" << i * i + fSum[i] + sSum[K - i] << endl;
        ans = max(ans, i * i + fSum[i] + sSum[K - i]);
    }
    cout << ans << endl;

    return 0;
}