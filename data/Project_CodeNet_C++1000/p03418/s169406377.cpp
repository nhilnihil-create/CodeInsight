#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N, K;

int main() {
    cin >> N >> K;
    if (K == 0) {
        cout << N * N << endl;
        return 0;
    }
    // bを固定

    ll ans = 0;
    for (int b = 1; b <= N; b++) {
        // はみ出たぶん
        ll r = N % b;
        ans += max(r - K + 1, 0LL);

        // 周期丸ごとを含む分
        ll p = N / b;
        ans += p * max((b - 1 - K) + 1, 0LL);
    }

    cout << ans << endl;
}