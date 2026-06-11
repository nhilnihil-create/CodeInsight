#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i < (int)(n); i++)
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll K, A, B;
    cin >> K >> A >> B;

    ll ans = 0;
    if (B - A <= 2) ans = K + 1;
    else {
        ll sell_num = (K - (A - 1)) / 2;
        ans = sell_num * (B - A) + A;
        if (K - 2 * sell_num - (A - 1) == 1) ans++;
    }

    cout << ans << endl;

    return 0;
}