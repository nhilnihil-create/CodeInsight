#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int cnt[30][100010] = {};

int main() {

    int n, C; cin >> n >> C;

    // いもす法
    for (int i = 0; i < n; ++i) {
        int s, t, c; cin >> s >> t >> c;
        --s;
        --c;

        cnt[c][s]++;
        cnt[c][t]--;
    }

    for (int i = 0; i < C; ++i) {
        for (int j = 1; j < 100010; ++j) {
            cnt[i][j] += cnt[i][j - 1]; // 復元
        }
    }

    for (int i = 0; i < C; ++i) {
        for (int j = 0; j < 100010; ++j) {
            if (cnt[i][j] == 2) { // 連続する部分は2になる
                cnt[i][j] = 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 100010; ++i) {
        int sum = 0;
        for (int j = 0; j < C; ++j) {
            if (cnt[j][i] == 1) sum++;
        }

        ans = max(ans, sum);
    }

    cout << ans << endl;
}