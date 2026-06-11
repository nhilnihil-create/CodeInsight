#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, M, K, S;
    cin >> N >> M;
    vector<int> s(M, 0), p(M);
    rep(i, M) {
        cin >> K;
        rep(j, K) {
            cin >> S;
            s[i] |= (1 << (S - 1));
        }
    }
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