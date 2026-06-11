#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

ll N, K;

int main() {
    cin >> N >> K;

    if (K == 0) {
        cout << N * N << endl;
        return 0;
    }

    ll ans = 0;
    for (ll b = 1; b <= N; b++) {
        // mod を足す
        // ans += (N % b);
        ll r = N % b;
        ans += max(0LL, r - K + 1);

        ll q = N / b;
        ans += q * (max(0LL, b - K));
    }

    cout << ans << endl;
}