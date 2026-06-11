#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<int> k(M);
    vector<vector<int>> s(M);
    rep(i, M) {
        cin >> k[i];
        rep(j, k[i]) {
            int tmp;
            cin >> tmp;
            --tmp;
            s[i].push_back(tmp);
        }
    }
    vector<int> p(M);
    rep(i, M) cin >> p[i];

    int ans = 0;
    for (int bit = 0; bit < (1 << N); ++bit) {
        bool ok = true;
        rep(i, M) {
            int cnt = 0;
            rep(j, k[i]) {
                if (bit & (1 << s[i][j])) {
                    ++cnt;
                }
            }
            if (cnt % 2 != p[i]) {
                ok = false;
                break;
            }
        }
        if (ok) ++ans;
    }
    cout << ans << endl;
}