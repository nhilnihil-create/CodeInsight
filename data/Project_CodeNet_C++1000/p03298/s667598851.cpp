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

    string lh = s.substr(0, n), rh = s.substr(n, n);
    reverse(rh.begin(), rh.end());

    using P = tuple<string, string>;
    vector<P> ss;
    rep(i, 1 << n)
    {
        string a, b;
        rep(j, n)
        {
            if (((i >> j) & 1) == 1) {
                a.push_back(rh[j]);
            } else {
                b.push_back(rh[j]);
            }
        }
        ss.push_back(P(a, b));
    }
    sort(ss.begin(), ss.end());

    int64_t result = 0;
    rep(i, 1 << n)
    {
        string a, b;
        rep(j, n)
        {
            if (((i >> j) & 1) == 1) {
                a.push_back(lh[j]);
            } else {
                b.push_back(lh[j]);
            }
        }
        P key = P(a, b);
        result += upper_bound(ss.begin(), ss.end(), key) - lower_bound(ss.begin(), ss.end(), key);
    }
    cout << result << endl;

    return 0;
}