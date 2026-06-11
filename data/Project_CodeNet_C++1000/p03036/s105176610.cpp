#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;
using P = pair<int, int>;

int main() {
    int r, d, x20, ans = 0;
    cin >> r >> d >> x20;
    rep(i, 10) {
        if (i == 0)
            ans += r * x20 - d;
        else
            ans = r * ans - d;
        cout << ans << endl;
    }
    return 0;
}