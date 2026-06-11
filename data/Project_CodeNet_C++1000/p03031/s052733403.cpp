#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> S(N);
    rep(i, M) {
        int k; cin >> k;
        rep(j, k) {
            int s; cin >> s;
            s--;
            S[s] |= 1 << i;
        }
    }
    auto rec = [&](auto &&rec, int depth, int oi) -> int {
        if(depth == N) {
            if(oi == 0) return 1;
            else return 0;
        }
        return rec(rec, depth + 1, oi) + rec(rec, depth + 1, oi ^= S[depth]);
    };
    int bit = 0;
    rep(i, M) {
        int p; cin >> p;
        if(p) bit |= 1 << i;

    }
    cout << rec(rec, 0, bit) << '\n';
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}
