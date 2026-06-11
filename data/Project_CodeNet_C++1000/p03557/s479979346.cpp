#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int N;

void solve() {
    cin >> N;
    vector<ll> A(N), B(N), C(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];
    for (int i = 0; i < N; ++i) cin >> C[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        // A[j] < B[i]を満たすjの個数
        ll x = distance(A.begin(), lower_bound(A.begin(), A.end(), B[i]));

        // C[k] > B[i]を満たすkの個数
        ll y = distance(lower_bound(C.begin(), C.end(), B[i] + 1), C.end());
        
        ans += x * y;
    }
    cout << ans << endl;
}

int main() {
    solve();
}