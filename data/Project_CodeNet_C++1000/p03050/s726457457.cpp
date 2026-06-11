#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
using namespace std;
typedef long long ll;

int main() {
    ll N; cin >> N;
    ll ans = 0;
    for (ll i = 1; i * i <= N; i++) {
        if (N % i != 0) continue;
        if (i * i == N) {
            if (i > 1 && N % (i - 1) == N / (i - 1)) {
                ans += i - 1;
            }
        } else {
            if (i > 1 && N % (i - 1) == N / (i - 1)) {
                ans += i - 1;
            }
            if (N / i > 1 && N % (N / i - 1) == N / (N / i - 1)) {
                ans += N / i - 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}