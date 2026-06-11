#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

void solve(long long N, long long K, std::vector<long long> x) {
    ll ans = 1e10;
    if (x[0] >= 0 && x[N - 1] >= 0) {
        cout << x[K - 1] << endl;
        return;
    }
    if (x[0] <= 0 && x[N - 1] <= 0) {
        cout << abs(x[N - K]) << endl;
        return;
    }
    for (ll i = 0; i <= N - K; i++) {
        ll left = x[i];
        ll right = x[i + K - 1];

        ll minabs = min(abs(left), abs(right));
        ll maxabs = max(abs(left), abs(right));
        ll tmpans = 2 * minabs + maxabs;
        ans = min(ans, tmpans);
    }
    cout << ans << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    long long K;
    scanf("%lld", &K);
    std::vector<long long> x(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &x[i]);
    }
    solve(N, K, std::move(x));
    return 0;
}
