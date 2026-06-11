#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    ll N, M;
    cin >> N >> M;

    ll lim = M / N, ans = 1;
    for (ll i = 1; i * i <= M; ++i) {
        if (i > lim)
            break;

        if (M % i == 0) {
            ans = max(ans, i);

            if(M/i<=lim)
                ans = max(ans, M / i);
        }
    }

    cout << ans << endl;

    return 0;
}