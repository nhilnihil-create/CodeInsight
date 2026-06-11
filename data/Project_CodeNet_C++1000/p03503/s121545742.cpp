#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    int N;
    cin >> N;
    vector<vector<int>> F(N, vector<int>(10));
    vector<vector<ll>> P(N, vector<ll>(11));
    rep(i, N) {
        rep(j, 10) { cin >> F[i][j]; }
    }

    rep(i, N) {
        rep(j, 11) { cin >> P[i][j]; }
    }

    ll ans = -1e10;
    for (int bit = 1; bit < (1 << 10); bit++) {
        vector<int> open(10, 0);
        rep(i, 10) {
            if (bit & (1 << i)) {
                open[i] = 1;
            }
        }

        ll temp = 0;
        rep(i, N) {
            int cnt = 0;
            rep(j, 11) {
                if (F[i][j] == 1 && F[i][j] == open[j])
                    cnt++;
            }

            temp += P[i][cnt];
        }

        ans = max(ans, temp);
    }

    cout << ans << endl;
}