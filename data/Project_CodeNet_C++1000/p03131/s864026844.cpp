#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int64_t k, a, b;
    cin >> k >> a >> b;
    int64_t ans = 0;
    if (b < a + 3) ans = k + 1;
    else {
        ans = (k - a + 1) / 2 * (b - a) + a;
        if ((k - a + 1) % 2 == 1) ans += 1;
    }
    cout << ans << endl;
}