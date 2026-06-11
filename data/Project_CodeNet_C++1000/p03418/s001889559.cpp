#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;

int main() {
    ll N, K, ans = 0, z = 0; cin >> N >> K;
    for (ll i = 1; i <= N; i++) ans += N/i * max(i-K, z) + max(z, N%i - K +1);
    if (K == 0) ans -= N;
    cout << ans << endl;
}
