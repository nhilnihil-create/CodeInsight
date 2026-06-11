#include <algorithm>
#include <bitset>
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
    int n, k;
    cin >> n >> k;
    vector<int64_t> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    vector<int64_t> acc(n + 1);
    irep(i, n)
    {
        if (i == 0) {
            acc[i] = 0;
        } else {
            acc[i] = acc[i - 1] + a[i - 1];
        }
    }
    /*rep(i, n)
    {
        for (int j = i + 1; j <= n; j++) {
            int64_t p = acc[j] - acc[i];
            //cout << "i=" << i << " j=" << j << " p=" << p << " bit:\t" << bitset<64>(p) << endl;
        }
    }*/

    int64_t result = 0;
    rrep(i, 64)
    {
        int64_t f = 1L << i;
        int64_t tmp = result | f;

        int cnt = 0;
        rep(i, n)
        {
            for (int j = i + 1; j <= n; j++) {
                int64_t p = acc[j] - acc[i];
                if ((p & tmp) == tmp) {
                    cnt++;
                }
            }
        }
        if (cnt >= k) {
            result = tmp;
        }
    }
    cout << result << endl;

    return 0;
}