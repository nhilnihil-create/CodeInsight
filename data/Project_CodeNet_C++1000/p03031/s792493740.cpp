#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s;
    s.assign(m, vector<int>());
    vector<int> k(m);
    vector<int> p(m);
    for (int i = 0; i < m; i++) {
        cin >> k[i];
        for (int j = 0; j < k[i]; j++) {
            int s_temp;cin >> s_temp;
            s_temp--;
            s[i].push_back(s_temp);
        }
    }
    for (int i = 0; i < m; i++) cin >> p[i];
    int ans = 0;
    for (int i = 0; i < 1<<n; i++) {
        int i_temp = i;
        vector<int> switch_on(n, false);
        vector<int> bulbs(m);
        bool is_ok = true;
        for (int j = 0; j < n; j++) if (i_temp & 1<<j) switch_on[j] = true;
        for (int j = 0; j < m; j++) {
            int on = 0;
            for (auto a: s[j]) if (switch_on[a]) on++;
            if (on % 2 != p[j]) is_ok = false;
        }
        if (is_ok) ans++;
    }
    cout << ans << endl;
    return 0;
}