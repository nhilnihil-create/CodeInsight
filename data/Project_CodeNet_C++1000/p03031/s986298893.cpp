#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, m,ans;

    cin >> n >> m;
    vector<vector<int>> lmp(m);
    vector<int> p(m);
    rep(i, m) {
        int k;
        cin >> k;
        rep(j, k) {
            int ss;
            cin >> ss;
            lmp[i].push_back(ss-1);
        }
    }
    rep(i, m)
        cin >> p[i];

    ans = 0;
    // {0, 1, ..., n-1} の部分集合の全探索
    for (int bit = 0; bit < (1 << n); ++bit) {
        vector<int> S(n);
        for (int i = 0; i < n; ++i) {
            if (bit & (1 << i)) { // 列挙に i が含まれるか
                S[i] = 1;
            }
        }
        //電球チェック
        int flg = 0;
        rep(i, m) {
            int cnt = 0;
            rep(j, lmp[i].size()) {
                if (S[lmp[i][j]] == 1)
                    ++cnt;
            }
            if (cnt % 2 != p[i]) {
                ++flg;
                break;;
            }
        }
        if (flg == 0)
            ++ans;
    }

	cout << ans << endl;
	return 0;
}
