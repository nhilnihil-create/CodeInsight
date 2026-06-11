#include <algorithm>
#include <iostream>
#include <vector>

#define rep(inc, bgn, end) for (int inc = bgn; inc < end; ++inc)
#define repe(inc, bgn, end) for (int inc = bgn; inc <= end; ++inc)

using ll = long long;
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;
    int val = -1;
    rep(i, 0, n) {
        int _val = -1;
        cin >> _val;
        if (i > 0) {
            val = gcd(val, _val);
        } else {
            val = _val;
        }
    }
    cout << val << endl;
    return 0;
}
