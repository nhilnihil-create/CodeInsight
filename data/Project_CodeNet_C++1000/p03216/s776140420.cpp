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

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int64_t> mCnt(n);
    rrep(i, n)
    {
        if (i == n - 1) {
            mCnt[i] = (s[i] == 'M' ? 1 : 0);
        } else {
            mCnt[i] = mCnt[i + 1] + (s[i] == 'M' ? 1 : 0);
        }
    }

    vector<int64_t> dCnt(n);
    rrep(i, n)
    {
        if (i == n - 1) {
            dCnt[i] = (s[i] == 'D' ? 1 : 0);
        } else {
            dCnt[i] = dCnt[i + 1] + (s[i] == 'D' ? 1 : 0);
        }
    }

    vector<int64_t> a(n);
    rrep(i, n)
    {
        if (i == n - 1) {
            a[i] = 0;
        } else {
            a[i] = a[i + 1] + (s[i] == 'D' ? mCnt[i + 1] : 0);
        }
    }

    int q;
    cin >> q;
    rep(i, q)
    {
        int k;
        cin >> k;

        int64_t result = 0;
        rep(j, n)
        {
            if (s[j] == 'C' && j >= 2) {
                int l = max(0L, j - k + 1);
                int64_t t = a[l] - a[j] - (dCnt[l] - dCnt[j]) * mCnt[j];
                result += t;
                // cout
                //     << "i=" << i << " j=" << j << " k=" << k << " l=" << l << " t=" << t << " " << (dCnt[l] - dCnt[j]) * mCnt[i] << endl;
            }
        }
        cout << result << endl;
    }

    return 0;
}