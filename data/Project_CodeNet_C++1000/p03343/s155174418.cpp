#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, q; cin >> n >> k >> q;
    vector<int> a(n), b;
    for (int i = 0; i < n; i++) cin >> a[i];
    b = a; sort(b.begin(), b.end());
    int ans = 2e9; int minval = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && b[i] <= minval) continue;
        int t = b[i];
        vector<int> v, w;
        for (int j = 0; j < n; j++) {
            if (a[j] < t) {
                if (v.empty()) continue;
                if (v.size() >= k) {
                    sort(v.rbegin(), v.rend());
                    while (v.size() >= k) {
                        w.emplace_back(v.back());
                        v.pop_back();
                    } 
                }
                v.clear();
            } else {
                v.emplace_back(a[j]);
            }
        }
        if (!v.empty()) {
            if (v.size() >= k) {
                sort(v.rbegin(), v.rend());
                while (v.size() >= k) {
                    w.emplace_back(v.back());
                    v.pop_back();
                }
            }
        }        
        if (w.size() < q) continue;
        sort(w.begin(), w.end());
        ans = min(ans, w[q-1] - w[0]);
        minval = max(minval, w[0]);
    }
    cout << ans << endl;
    return 0;
}