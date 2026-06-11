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

int a[50];

int main()
{
    int n;
    cin >> n;
    rep(i, n)
    {
        cin >> a[i];
    }

    int b = 1e6 + 1, u = -1e6 - 1;
    int bIdx, uIdx;
    rep(i, n)
    {
        if (b > a[i]) {
            b = a[i];
            bIdx = i;
        }
        if (u < a[i]) {
            u = a[i];
            uIdx = i;
        }
    }

    vector<pair<int, int>> ans;

    if ((int64_t)b * u <= 0) {
        if (u + b >= 0) {
            rep(i, n)
            {
                ans.push_back(make_pair(uIdx, i));
                a[i] += a[uIdx];
            }
        } else {
            rep(i, n)
            {
                ans.push_back(make_pair(bIdx, i));
                a[i] += a[bIdx];
            }
        }
    }

    if (a[0] >= 0) {
        rep(i, n)
        {
            if (i < n - 1) {
                ans.push_back(make_pair(i, i + 1));
                a[i + 1] += a[i];
            }
        }
    } else {
        rrep(i, n)
        {
            if (i > 0) {
                ans.push_back(make_pair(i, i - 1));
                a[i - 1] += a[i];
            }
        }
    }

    cout << ans.size() << endl;
    for (const auto& p : ans) {
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }

    return 0;
}