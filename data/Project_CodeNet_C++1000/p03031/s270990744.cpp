#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    // bit全探索
    ll N, M;
    cin >> N >> M;
    vector<int> S[M];
    rep(i, M) {
        ll k;
        cin >> k;
        vector<int> A(k);
        rep(i, k) cin >> A[i];
        rep(i, k) --A[i];
        S[i] = A;
    }
    vector<int> L(M);
    rep(i, M) cin >> L[i];
    ll ans = 0;        
    for (int bit = 0; bit < (1<<N); bit++) {
        vector<int> cnt(M);
        for (int i = 0; i < N; i++) {
            if ((bit>>i) & 1) {
                // i番目のスイッチがon   // 0-indexed
                for (int j = 0; j < M; j++) {
                    if (count(S[j].begin(), S[j].end(), i)) {
                        cnt[j] ^= 1;
                    }
                }
            }
        }
        ll temp = 0;
        rep(i, M) {
            if (L[i] == cnt[i]) temp++;
        }
        if (temp == M) ans++;
    }
    cout << ans << '\n';
    return 0;
}