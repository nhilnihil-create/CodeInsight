#include <bits/stdc++.h>
using ll = long long;
using namespace std;

constexpr int inf = 1e9;
constexpr ll linf = 1e18;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, c; cin >> n >> c;
    int d[c][c];
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < c; j++) cin >> d[i][j];
    }
    int cnt[c][3];
    memset(cnt, 0x00, sizeof(cnt));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cij; cin >> cij; cij--;
            cnt[cij][(i + j + 2) % 3]++;
        }
    }

    int ans = inf;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < c; j++) {
            for (int k = 0; k < c; k++) {
                if (i == j || j == k || k == i) continue;
                int tmp = 0;
                for (int l = 0; l < c; l++) {
                    tmp += d[l][i] * cnt[l][0];
                    tmp += d[l][j] * cnt[l][1];
                    tmp += d[l][k] * cnt[l][2];
                }
                ans = min(ans, tmp);
            }
        }
    }
    cout << ans << endl;
    return 0;
}