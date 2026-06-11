#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> F(n);
    rep(i, n) {
        rep(j, 10) {
            int tmp; cin >> tmp;
            F[i].push_back(tmp);
        }
    }
    vector<vector<int>> P(n);
    rep(i, n) {
        rep(j, 11) {
            int tmp; cin >> tmp;
            P[i].push_back(tmp);
        }
    }


    int res = -1000000005;
    for (int i = 0; i < (1<<10); i++) {
        if (i == 0) continue;
        int sum_p = 0;

        // 店
        for (int j = 0; j < n; j++) {

            int cnt = 0;
            for (int k = 0; k < 10; k++) {
                if (i & (1<<k)) {
                    if (F[j][k] == 1) {
                        ++cnt;
                    }
                }
            }

            sum_p += P[j][cnt];
        }

        res = max(res, sum_p);
    }

    cout << res << endl;
}