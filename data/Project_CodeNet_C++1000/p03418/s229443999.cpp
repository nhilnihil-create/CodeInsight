#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll N, K;
    cin >> N >> K;
    if (K == 0) {
        cout << N * N << endl;
        return 0;
    }
    ll ans = 0;
    for (ll b = K + 1; b <= N; b++) {
        ans += (b - K) * (N / b) + max(N % b - K + 1, 0LL);
    }
    cout << ans << endl;
}