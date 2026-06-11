#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> itv(M);
    rep(i, M) cin >> itv[i].second >> itv[i].first;

    sort(itv.begin(), itv.end());

    int ans = 0, now = 0;
    rep(i, M) {
        if (now <= itv[i].second) {
            ans++;
            now = itv[i].first;
        }
    }

    cout << ans << endl;

    return 0;
}