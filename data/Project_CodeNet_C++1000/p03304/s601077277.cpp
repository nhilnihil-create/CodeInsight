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

int main()
{
    cout << fixed << setprecision(10);
    int64_t n, m, d;
    cin >> n >> m >> d;

    int64_t a = (n - d) * (m - 1);
    if (d != 0) {
        a *= 2;
    }
    cout << (double)a / n / n << endl;
    return 0;
}