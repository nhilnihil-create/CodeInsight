#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using ll = long long;
#define rep(inc, bgn, end) for (int inc = bgn; inc < end; ++inc)
#define repe(inc, bgn, end) for (int inc = bgn; inc <= end; ++inc)

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    int n, x;
    cin >> n >> x;

    int ans = -1;
    rep(i, 0, n) {
        int pos;
        cin >> pos;
        int len = abs(x - pos);
        if (ans < 0) {
            ans = len;
        } else {
            ans = gcd(ans, len);
        }
    }

    cout << ans << endl;
    return 0;
}
