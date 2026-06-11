#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<int> k(M), s(M, 0);
    rep(i, M) {
        cin >> k[i];
        rep(j, k[i]) {
            int tmp;
            cin >> tmp;
            --tmp;
            s[i] |= (1 << tmp);
        }
    }
    vector<int> p(M);
    rep(i, M) cin >> p[i];

    int ans = 0;
    for (int bit = 0; bit < (1 << N); ++bit) {
        int ok = 1;
        rep(i, M) {
            ok ^= (__builtin_popcount(bit & s[i]) % 2 ^ p[i]);
            if (!ok) break;
        }
        if (ok) ++ans;
    }
    cout << ans << endl;
}