#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

int main() {
    ll N, H;
    cin >> N >> H;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i] >> B[i];
    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());
    ll X = A[0];

    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        ++ans;
        H -= max(X, B[i]);
        if (H <= 0) break;
    }

    if (H > 0)
        ans += (H + X - 1) / X;
    cout << ans << endl;
}