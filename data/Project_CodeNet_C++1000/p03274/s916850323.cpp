#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    int N, K;
    cin >> N >> K;
    ll x[N];
    for(int i = 0; i < N; i++) cin >> x[i];

    ll ans = inf;

    for(int i = 0; i < N - K + 1; i++) {
        ll tmp;
        if(x[i] >= 0)
            tmp = x[i + K - 1];
        else if(x[i + K - 1] <= 0) {
            tmp = -1 * x[i];
        } else {
            tmp = abs(x[i]) + abs(x[i + K - 1]);
            if(x[i] * x[i + K - 1] < 0) tmp += min(abs(x[i]), abs(x[i + K - 1]));
        }
        ans = min(ans, tmp);
    }

    cout << ans << "\n";
    return 0;
}