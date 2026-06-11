#include <bits/stdc++.h>
using namespace std;

typedef long long i64;

i64 suma;
i64 a, b;

bool ok(i64 st, i64 dr, i64 l, i64 r)
{
    if (dr <= l)
        return dr * l <= suma;
    if (st >= r)
        return st * r <= suma;

    /// se suprapun
    double q = 1.0 * (st + r) / 2;
    i64 x = q;
    if (1.0 * x == q) {
        if (x * x > suma)
            return false;
    }
    else if (x * (x + 1) > suma)
        return false;
    return true;
}

bool split(int x, int y, int l, int r)
{
    if (y < x || r < l)
        return true;
    if (x <= a && a <= y) {/// impart
        int len = a - x;
        return split(x, x + len - 1, r - len + 1, r) &&
             split(x + len + 1, y + 1, l, r - len);
    }
    if (l <= b && b <= r) {
        int len = b - l;
        return split(y - len + 1, y, l, l + len - 1) &&
                split(x, y - len, l + len + 1, r + 1);
    }
    return ok(x, y, l, r);
}

bool cbin(int x)
{
    /// iau primii x
    return split(1, x, 1, x);
}


int main()
{
    int t;
    cin >> t;

    while (t--) {
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        suma = 1ll * a * b - 1;
        int p(0), q(1 << 30);
        while (q) {
            if (cbin(p + q))
                p += q;
            q /= 2;
        }
        cout << p << '\n';
    }
    return 0;
}
