#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;


int main() {
    ll N, K;
    cin >> N >> K;

    if (K == 0) {
        cout << N * N << endl;
        return 0;
    }

    ll ans = 0;
    for (ll i = 1; i <= N; i++) {
        if (i - 1 < K) continue;
        ll cnt = i - 1LL - K + 1LL;
        ans += cnt * (N / i);
        ans += max(0LL, N % i - K + 1);
    }
    cout << ans << endl;
}