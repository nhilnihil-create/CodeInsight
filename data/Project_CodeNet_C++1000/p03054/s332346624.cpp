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
    int h, w, n;
    cin >> h >> w >> n;

    int sr, sc;
    cin >> sr >> sc;

    string s, t;
    cin >> s >> t;

    int lr = 0, rr = h + 1;
    int lc = 0, rc = w + 1;
    rrep(i, n)
    {
        if (t[i] == 'U') {
            rr = min(rr + 1, h + 1);
        } else if (t[i] == 'D') {
            lr = max(lr - 1, 0);
        } else if (t[i] == 'R') {
            lc = max(lc - 1, 0);
        } else {
            rc = min(rc + 1, w + 1);
        }

        if (s[i] == 'U') {
            lr = lr + 1;
        } else if (s[i] == 'D') {
            rr = rr - 1;
        } else if (s[i] == 'R') {
            rc = rc - 1;
        } else {
            lc = lc + 1;
        }

        if (lc + 1 >= rc || lr + 1 >= rr) {
            cout << "NO" << endl;
            return 0;
        }
    }

    if (sr <= lr || sr >= rr || sc <= lc || sc >= rc) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }

    return 0;
}