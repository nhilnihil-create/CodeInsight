#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

int64_t dceil(int64_t, int64_t);
int64_t dfloor(int64_t, int64_t);

int64_t dceil(int64_t x, int64_t y)
{
    if (y < 0) {
        return dceil(-x, -y);
    }
    if (x < 0) {
        return -dfloor(-x, y);
    }
    return (x + y - 1) / y;
}

int64_t dfloor(int64_t x, int64_t y)
{
    if (y < 0) {
        return dfloor(-x, -y);
    }
    if (x < 0) {
        return -dceil(-x, y);
    }
    return x / y;
}

const int64_t MOD = 998'244'353L;

int64_t dpow(int64_t x, int64_t y)
{
    if (y == 0) {
        return 1;
    }
    if (y % 2 == 0) {
        return dpow(x * x % MOD, y / 2);
    } else {
        return x * dpow(x, y - 1) % MOD;
    }
}

int64_t inv(int64_t x)
{
    return dpow(x, MOD - 2);
}

using S = tuple<int64_t, int64_t, int64_t, bool>;
S gcd(int64_t a, int64_t b, int64_t k)
{
    if (a == 0) {
        return S(b, 0, k / b, k % b == 0);
    } else {
        int64_t d, x, y;
        bool p;
        tie(d, x, y, p) = gcd(b % a, a, k);

        return S(d, y - b / a * x, x, p);
    }
}

int main()
{
    int64_t n, a, b, k;
    cin >> n >> a >> b >> k;

    int64_t d, x, y;
    bool p;
    tie(d, x, y, p) = gcd(a, b, k);
    if (!p) {
        cout << 0 << endl;
        return 0;
    }

    a /= d;
    b /= d;

    vector<int64_t> fact(n + 1);
    irep(i, n)
    {
        if (i == 0) {
            fact[i] = 1;
        } else {
            fact[i] = fact[i - 1] * i % MOD;
        }
    }

    int64_t result = 0;
    for (int64_t t = dceil(-x, b); x + b * t <= n; t++) {
        int64_t w = x + b * t, z = y - a * t;
        if (z >= 0 && z <= n) {
            int64_t c1 = fact[n] * inv(fact[n - w]) % MOD * inv(fact[w]) % MOD;
            int64_t c2 = fact[n] * inv(fact[n - z]) % MOD * inv(fact[z]) % MOD;
            result += c1 * c2 % MOD;
            result %= MOD;
        }
    }
    cout << result << endl;

    return 0;
}