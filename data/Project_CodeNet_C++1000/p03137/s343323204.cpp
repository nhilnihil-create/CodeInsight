// 7/3
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> X(M);
    rep(i, M) cin >> X[i];
    sort(X.begin(), X.end());

    vector<int> L(M-1);
    rep(i, M-1) L[i] = X[i+1] - X[i];
    sort(L.begin(), L.end(), greater<int>());

    // rep(i, L.size()) cout << L[i] << " ";
    // cout << endl;

    int ans = 0;
    if (N >= M) ans = 0; // cout << 0 << endl;
    else {
        ans = X[M-1] - X[0];
        rep(i, N-1) {
            ans -= L[i];
        }
    }
    cout << ans << endl;
}