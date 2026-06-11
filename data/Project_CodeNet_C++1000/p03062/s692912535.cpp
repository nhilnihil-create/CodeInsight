#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    sort(A.begin(), A.end());

    for (int i = 0; 2 * i <= N - 1; ++i) {
        ll sum;
        if (2 * i == N - 1) {
            sum = A[N - 2] + A[N - 1];
        } else
            sum = A[2 * i] + A[2 * i + 1];
        if (-sum > sum) {
            A[2 * i] *= -1;
            A[2 * i + 1] *= -1;
        }
    }
    ll ans = 0;
    rep(i, N) ans += A[i];
    cout << ans << endl;
}