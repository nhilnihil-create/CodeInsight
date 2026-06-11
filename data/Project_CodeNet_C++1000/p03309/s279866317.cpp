// 7/16
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    vector<ll> B(N);
    rep(i, N) B[i] = A[i] - (i + 1);
    sort(B.begin(), B.end());

    ll b = B[N/2];
    ll ans = 0;
    rep(i, N) {
        ans += abs(B[i] - b);
    }

    // if (b % 2 == 0) {
    //     b = B[N/2-1];
    //     int ans2 = 0;
    //     rep(i, N) {
    //         ans2 += abs(B[i] - b);
    //     }
    //     ans = min(ans, ans2);
    // }

    cout << ans << endl;
    return 0;
}