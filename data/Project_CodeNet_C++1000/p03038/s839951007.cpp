#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, M;
    cin >> N >> M;

    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    vector<pair<ll, ll>> C(M);
    rep(i, M) {
        ll b, c;
        cin >> b >> c;
        C[i] = make_pair(c, b);
    }

    sort(A.begin(), A.end());
    sort(C.begin(), C.end(), greater<pair<ll, ll>>());

    int idx_A = 0;
    rep(i, M) {
        rep(j, C[i].second) {
            if (C[i].first <= A[idx_A] || idx_A == N)
                break;
            else {
                A[idx_A] = C[i].first;
                ++idx_A;
            }
        }
        if (C[i].first <= A[idx_A] || idx_A == N) break;
    }

    ll ans = 0;
    rep(i, N) ans += A[i];

    cout << ans << endl;
}