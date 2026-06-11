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

    vector<ll> S(N + 1);
    S[0] = 0;
    for (int i = 0; i < N; ++i) {
        int j = N - 1 - i;
        int index = distance(C.begin(), lower_bound(C.begin(), C.end(), B[j] + 1));
        S[i + 1] = S[i] + (N - index);
    }

    ll ans = 0;
    for(int i = 0; i < N; ++i)
    {
        int index = distance(B.begin(), lower_bound(B.begin(), B.end(), A[i] + 1));
        ans += S[N - index];
    }
    cout << ans << endl;
}

int main() {
    solve();
}