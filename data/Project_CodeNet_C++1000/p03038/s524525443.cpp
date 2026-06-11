#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    // Aの最小値から変えるか判定
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    sort(A.begin(), A.end());
    vector<P> BC;
    rep(i, M) {
        int b, c;
        cin >> b >> c;
        BC.emplace_back(c, b);
    }
    sort(BC.rbegin(), BC.rend());
    vector<int> X;
    for (auto p : BC) {
        int b = p.second, c = p.first;
        rep(i, b) {
            X.push_back(c);
            if (sz(X) == N) break;
        }
        if (sz(X) == N) break;
    }
    int length = min(N, sz(X));
    rep(i, length) A[i] = max(A[i], X[i]);
    ll ans = accumulate(A.begin(), A.end(), 0L);
    cout << ans << '\n';
    return 0;
}