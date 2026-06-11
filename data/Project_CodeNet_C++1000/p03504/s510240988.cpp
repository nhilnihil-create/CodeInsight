#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n, c;
    cin >> n >> c;
    vector<vector<int>> recording(c, vector<int>(100010, 0));
    rep(i, n) {
        int s, t, c;
        cin >> s >> t >> c;
        recording[c - 1][s]++;
        recording[c - 1][t + 1]--;
    }
    rep(i, c) {
        rep(j, 100009) {
            recording[i][j + 1] += recording[i][j];
        }
    }
    int ans = 0;
    rep(j, 100010) {
        int running = 0;
        rep(i, c) {
            if(recording[i][j]) running++;
        }
        ans = max(ans, running);
    }
    cout << ans << endl;
}
