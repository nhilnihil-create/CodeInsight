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
    int n;
    cin >> n;
    vector<int> d(n);
    rep(i, n)
    {
        cin >> d[i];
    }
    sort(d.begin(), d.end());

    vector<int> d1, d2;
    rep(i, n)
    {
        if (i % 2 == 0) {
            d1.push_back(d[i]);
        } else {
            d2.push_back(d[i]);
        }
    }

    int s = d[0];
    if (n >= 2) {
        s = min(s, 24 - d[n - 1] - d[n - 2]);
    }

    for (int i = 1; i < d1.size(); i++) {
        s = min(s, d1[i] - d1[i - 1]);
    }
    for (int i = 1; i < d2.size(); i++) {
        s = min(s, d2[i] - d2[i - 1]);
    }

    cout << s << endl;

    return 0;
}