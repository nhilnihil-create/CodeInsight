#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n);
    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = {a[i], i};
    }
    sort(b.begin(), b.end());
    int ans = b[q - 1].first - b[0].first;
    set<int> st;
    st.emplace(-1);
    st.emplace(n);
    st.emplace(b[0].second);
    for (int ii = 1; ii < n; ii++) {
        if (b[ii].first == b[ii - 1].first) {
            st.emplace(b[ii].second);
            continue;
        }
        vector<int> pos;
        int i = -1;
        for (int j : st) {
            if (j == -1) continue;
            vector<int> t;
            for (int l = i + 1; l < j; l++) {
                t.emplace_back(a[l]);
            }
            if (t.size() >= k) {
                sort(t.begin(), t.end());
                for (int l = 0; l <= t.size() - k; l++) {
                    pos.emplace_back(t[l]);
                }
            }
            i = j;
        }
        if (pos.size() >= q) {
            sort(pos.begin(), pos.end());
            ans = min(ans, pos[q - 1] - pos[0]);
        }
        st.emplace(b[ii].second);
    }
    cout << ans << '\n';
    return 0;
}
