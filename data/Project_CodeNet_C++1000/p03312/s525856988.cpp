#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        A[i] += A[i - 1];
    }

    ll ans = 1e18;
    for (int q = 2; q <= N - 2; q++) {
        ll Left = A[q];
        ll Right = A[N] - A[q];

        int p = lower_bound(A.begin() + 1, A.begin() + q, Left / 2) - A.begin();
        if (p == q)
            p--;

        ll P = A[p];
        ll Q = A[q] - A[p];
        if (p + 1 < q && abs(A[q] - 2 * A[p + 1]) < abs(P - Q)) {
            P = A[p + 1];
            Q = A[q] - A[p + 1];
        }
        if (p - 1 >= 1 && abs(A[q] - 2 * A[p - 1]) < abs(P - Q)) {
            P = A[p - 1];
            Q = A[q] - A[p - 1];
        }

        int r = lower_bound(A.begin() + q + 1, A.end(), A[q] + Right / 2) - A.begin();
        if (r == N) {
            r--;
        }

        ll R = A[r] - A[q];
        ll S = A[N] - A[r];
        if (r + 1 < N && abs(A[N] - 2 * A[r + 1] + A[q]) < abs(R - S)) {
            R = A[r + 1] - A[q];
            S = A[N] - A[r + 1];
        }
        if (r - 1 > q && abs(A[N] - 2 * A[r - 1] + A[q]) < abs(R - S)) {
            R = A[r - 1] - A[q];
            S = A[N] - A[r - 1];
        }

        ans = min(ans, abs(max({P, Q, R, S}) - min({P, Q, R, S})));
    }
    cout << ans << endl;
}
