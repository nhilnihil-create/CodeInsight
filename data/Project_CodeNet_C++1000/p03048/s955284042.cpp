#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    int r, g, b, n;
    cin >> r >> g >> b >> n;
    int ans = 0;
    rep(x, n + 1) {
        rep(y, n + 1) {
            if((n - r * x - g * y) % b == 0 && n - r * x - g * y >= 0) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
