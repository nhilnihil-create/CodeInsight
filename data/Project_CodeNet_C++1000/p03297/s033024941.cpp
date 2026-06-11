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

int64_t gcd(int64_t a, int64_t b)
{
    if (a == 0) {
        return b;
    }
    return gcd(b % a, a);
}

int64_t cnt(int64_t x, int64_t d)
{
    if (x < 0) {
        return 0;
    } else {
        return x / d;
    }
}

int main()
{
    int t;
    cin >> t;
    rep(i, t)
    {
        int64_t a, b, c, d;
        cin >> a >> b >> c >> d;

        if (a < b || d < b) {
            cout << "No" << endl;
        } else if (c >= b) {
            cout << "Yes" << endl;
        } else {
            if (1 > b - c - 1) {
                cout << "Yes" << endl;
            } else if (1 <= (a - c) % b && (a - c) % b <= b - c - 1) {
                cout << "No" << endl;
            } else {
                int64_t g = gcd(b, d);
                if (g == b) {
                    cout << "Yes" << endl;
                } else {

                    int64_t l = (c - a % b + 1 + b) % b, r = (b - a % b - 1 + b) % b;

                    int64_t n;
                    if (l <= r) {
                        n = cnt(r, g) - cnt(l - 1, g);
                    } else {
                        n = cnt(b - 1, g) - cnt(l - 1, g) + cnt(r, g);
                    }
                    cout << (n > 0 ? "No" : "Yes") << endl;
                }
            }
        }
    }
    return 0;
}