// 8/6過去問
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    ll N, K;
    cin >> N >> K;

    ll ans;

    if (K % 2 == 1) {
        ll num = N / K;
        ans = num * num * num;
    } else {
        ll num =  N / K;
        ans = num * num * num;

        ll num2 = (N + K/2) / K;
        ans += num2 * num2 * num2;
    }

    cout << ans << endl;
}