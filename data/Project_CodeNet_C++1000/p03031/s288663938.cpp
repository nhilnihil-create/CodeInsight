#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
using ll = long long;
using Grid = vector<vector<int>>;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> sw(N, vector<int>());
    vector<int> light(M, 0);
    vector<int> check(M);
    rep(i, M) {
        int k;
        cin >> k;
        rep(j, k) {
            int s;
            cin >> s;
            sw[s - 1].push_back(i);
        }
    }
    rep(i, M) {
        cin >> check[i];
    }
    ll ans = 0;
    for (int bit = 0; bit < (1 << N); bit++) {
        fill(light.begin(), light.end(), 0);
        for (int i = 0; i < N; i++) {
            if (bit & (1 << i)) {
                for (auto a : sw[i]) {
                    light[a]++;
                }
            }
        }
        bool ok = true;
        rep(i, M) {
            if (light[i] % 2 != check[i]) {
                ok = false;
                break;
            }
        }
        if (ok)
            ans++;
    }
    cout << ans << endl;
}