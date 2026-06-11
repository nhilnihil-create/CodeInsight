#include <bits/stdc++.h>
using namespace std;
int main() {
    int h, w; cin >> h >> w;
    vector<vector<int>> v(w, {h});
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int p, q; cin >> p >> q;
        v[q-1].push_back(p-1);
    }
    for (int i = 0; i < w; i++) {
        sort(v[i].begin(), v[i].end());
    }
    int cur = 0; int ans = 1e9;
    for (int i = 0; i < w; i++) {
        int t = *(upper_bound(v[i].begin(), v[i].end(), cur));
        ans = min(ans, t);
        if (i+1 < w) {
            cur++;
            int j = lower_bound(v[i+1].begin(), v[i+1].end(), cur) - v[i+1].begin();
            while (cur < h && cur == v[i+1][j]) {
                cur++; j++;
            }
            if (cur >= t) break;
        }
    }
    cout << ans << endl;
    return 0;
}