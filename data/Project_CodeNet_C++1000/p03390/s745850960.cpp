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
    int q;
    cin >> q;
    rep(i, q)
    {
        int64_t a, b;
        cin >> a >> b;
        int64_t rab = (int64_t)ceil(sqrt(a * b));
        int64_t result = 2 * (rab - 1) - (rab * (rab - 1) >= a * b ? 1 : 0);
        if (a != b) {
            result--;
        }

        cout << result << endl;
    }

    return 0;
}