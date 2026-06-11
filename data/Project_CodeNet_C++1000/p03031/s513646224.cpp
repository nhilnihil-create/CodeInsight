#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, m; cin >> n >> m;
    vector<vector<int>> s(m, vector<int>(n, -1));
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int t; cin >> t;
            s[i][j] = --t;
        }
    }
    vector<int> p(m);
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }
    int ans = 0;
    for (int bit = 0; bit < (1 << n); ++bit) {
        vector<bool> onSwitch(n, false);
        for (int i = 0; i < n; ++i) {
            if (bit & (1 << i)) {
                onSwitch[i] = true;
            }
        }
        int lightCnt = 0;
        for (int i = 0; i < m; i++) { // light
            int tmpSwitchOnCnt = 0;
            for (int j = 0; j < n; j++) { // switch
                if (s[i][j] == -1) continue;
                if (onSwitch[s[i][j]]) {
                    tmpSwitchOnCnt++;
                }
            }
            if (tmpSwitchOnCnt % 2 == p[i]) {
                lightCnt++;
            }
        }
        if (lightCnt == m) {
            ans++;
        }
    }
    cout << ans << endl;
	return 0;
}