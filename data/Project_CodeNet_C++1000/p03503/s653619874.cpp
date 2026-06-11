#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<vector<int>> F(N, vector<int> (10));
    vector<vector<int>> P(N, vector<int> (11));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> F[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 11; j++) {
            cin >> P[i][j];
        }
    }

    ll INF = 1LL << 60;
    ll ans = -INF;
    for (int bit = 0; bit < (1 << 10); bit++) {
        int num = 0;
        for (int i = 0; i < N; i++) {
            if (bit & (1 << i)) num++;
        }
        if (num == 0) continue;
        ll res = 0;
        for (int i = 0; i < N; i++) {
            int cnt = 0;
            for (int j = 0; j < 10; j++) {
                if (bit & (1 << j)) {
                    if (F[i][j] == 1) cnt ++;
                }
            }
            res += P[i][cnt];
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
}