#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long int64;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = 1<<29;
const long long  INFL = 1e18;
const int MOD = 1000000007;
const int MAX = 210000;
const int MAX_NUM = 999999999;
void solve() {
    int N, K; cin >> N >> K;
    map<int, vector<int>> mp;
    vector<int64> maxes, others;
    vector<int64> maxes_s(N + 1, 0), others_s(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        int64 t, d; cin >> t >> d;
        mp[t].push_back(d);
    }
    for (auto &p : mp) {
        auto tp = p.second;
        sort(tp.rbegin(), tp.rend());
        maxes.push_back(tp[0]);
        for (int i = 1; i < tp.size(); ++i) others.push_back(tp[i]);
    }
    sort(maxes.rbegin(), maxes.rend());
    sort(others.rbegin(), others.rend());
    for (int i = 0; i < maxes.size(); ++i) maxes_s[i + 1] = maxes_s[i] + maxes[i];
    for (int i = 0; i < others.size(); ++i) others_s[i + 1] = others_s[i] + others[i];
    int64 ans = 0;
    int kmax = min(K, (int)mp.size());
    for (int64 k = 1; k <= kmax; ++k) {
        int64 result = maxes_s[k] + others_s[K - k] + (k * k);
        ans = max(ans, result);
    }
    cout << ans << endl;
    return;
}
int main() {
    solve();
    return 0;
}