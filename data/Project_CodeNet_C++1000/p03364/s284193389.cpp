#include <algorithm>
#include <cmath>
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

const uint64_t R = 1'000'000'007L;

uint64_t dpow(uint64_t x, uint64_t y)
{
    if (y == 0) {
        return 1;
    }
    if (y % 2 == 0) {
        return dpow(x * x % R, y / 2);
    } else {
        return x * dpow(x, y - 1) % R;
    }
}

uint64_t inv(uint64_t x)
{
    return dpow(x, R - 2);
}

uint64_t comb(uint64_t n, uint64_t k)
{
    uint64_t a = 1, b = 1;
    for (uint64_t i = 0; i < k; i++) {
        a *= (n - i);
        a %= R;
        b *= i + 1;
        b %= R;
    }
    return a * inv(b) % R;
}

uint64_t perm(uint64_t n, uint64_t k)
{
    uint64_t r = 1;
    for (uint64_t i = 0; i < k; i++) {
        r *= (n - i);
        r %= R;
    }
    return r;
}

string grid[300];

int main()
{
    int n;
    cin >> n;
    rep(i, n)
    {
        cin >> grid[i];
    }

    int64_t result = 0;
    rep(a, n)
    {
        bool symmetric = true;
        rep(i, n) rep(j, n)
        {
            symmetric = symmetric && grid[(i + a) % n][j] == grid[(j + a) % n][i];
        }
        if (symmetric) {
            result += n;
        }
    }
    cout << result << endl;

    return 0;
}