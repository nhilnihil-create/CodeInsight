#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    vector<ll> C(N);
    rep(i, N) C[i] = A[i] + B[i];
    sort(C.rbegin(), C.rend());

    ll ans = 0;
    rep(i, N) ans -= B[i];
    for (int i = 0; i < N; i += 2) ans += C[i];

    cout << ans << endl;
}
