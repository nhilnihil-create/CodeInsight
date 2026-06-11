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

    ll cnt = N / K;
    if (K % 2 == 1) {
        cout << cnt * cnt * cnt << endl;
    } else {
        ll ans = cnt * cnt * cnt;

        // K / 2 の倍数を出す
        ll tmp = 0;
        for (int i = 1; i <= N; i++) {
            if (i % K == (K / 2)) tmp++;
        }
        ans += tmp * tmp * tmp;
        cout << ans << endl;
    }
}