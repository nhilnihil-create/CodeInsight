#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i < N; i++) {
        A[i] += A[i - 1];
    }

    ll ans = 1e18;
    for (int n = 1; n < N - 2; n++) {
        int pq = lower_bound(A.begin(), A.end(), (A[n] + 1) / 2) - A.begin();
        ll P = A[pq];
        ll Q = A[n] - A[pq];
        if (pq > 0 && abs(P - Q) > abs(A[pq - 1] - A[n] + A[pq - 1])) {
            P = A[pq - 1];
            Q = A[n] - A[pq - 1];
        }

        ll d = A[N - 1] - A[n];
        int rs = lower_bound(A.begin(), A.end(), A[n] + (d + 1) / 2) - A.begin();
        ll R = A[rs] - A[n];
        ll S = A[N - 1] - A[rs];
        if (rs > n + 1 && abs(R - S) > abs(A[rs - 1] - A[n] - A[N - 1] + A[rs - 1])) {
            R = A[rs - 1] - A[n];
            S = A[N - 1] - A[rs - 1];
        }

        ans = min(max({P, Q, R, S}) - min({P, Q, R, S}), ans);
    }
    cout << ans << endl;
}
