#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, m; cin >> n >> m;    // n:SW、m:電球
    vector<vector<int>> s(m, vector<int>(n));
    rep(i, m) {
        int k; cin >> k;
        s[i].resize(k);
        rep(j, k) {
            cin >> s[i][j];
            s[i][j]--;
        }
    }
    vector<int> p(m);
    rep(i, m) {
        cin >> p[i];
    }

    int ans = 0;
    for (int tmp = 0; tmp < (1 << n); tmp++) { // スイッチをbit全探索
        bitset<10> b(tmp);
        vector<int> m_sum(m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < s[i].size(); j++) {
                if (b.test(s[i][j]) == 1) {
                    m_sum[i]++;
                }
            }
        }
        bool is_all_on = true; 
        for (int i = 0; i < m; i++) {
            //printf("m_sum[%d]==%d\n", i, m_sum[i]);
            if ((m_sum[i] % 2) != p[i]) {
                is_all_on = false;
            }
        }
        if (is_all_on) {
            ans++;
        }
    }
    cout << ans << endl;
}
