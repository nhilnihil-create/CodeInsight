//#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//ifstream cin("x.in"); ofstream cout("x.out");

typedef long long i64;

i64 lim;

bool verif (i64 x, i64 dr, i64 l, i64 r) {
    if (dr <= l)
        return dr * l < lim;
    if (x >= r)
        return x * r < lim;

    double q = (double)(x + r) / 2;
    i64 mij = q;

    if ((double)mij == q) {
        return mij * mij < lim;
    }
    return mij * (mij + 1) < lim;
}

int _x, _y;
bool check (int a, int b, int l, int r) {
    if (b < a || r < l)
        return 1;

    if (a <= _x && _x <= b) {
        int len = _x - a;
        return check(a, a + len - 1, r - len + 1, r) && check(a + len + 1, b + 1, l, r - len);
    }

    if (l <= _y && _y <= r) {
        int len = _y - l;
        return check(b - len + 1, b, l, l + len - 1) && check(a, b - len, l + len + 1, r + 1);
    }

    return verif(a, b, l, r);
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(); cout.tie();
    int q;
    cin >> q;

    while (q --) {
        int x, y;
        cin >> x >> y;
        lim = 1LL * x * y;

        _x = x, _y = y;

        int ans = 0;
        for (int step = 1 << 30; step > 0; step >>= 1) {
            if (ans + step <= (1 << 30) - 1 + (1 << 30) && check(1, ans + step, 1, ans + step)) {
                ans += step;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
