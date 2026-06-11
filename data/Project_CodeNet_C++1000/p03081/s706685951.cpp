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
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;
    s = string(".") + s + string(".");

    using P = tuple<char, char>;
    vector<P> query;
    rep(i, q)
    {
        char t, d;
        cin >> t >> d;
        query.push_back(P(t, d));
    }

    int L = 0, R = n + 1;
    rrep(i, q)
    {
        if (L + 1 >= R) {
            cout << 0 << endl;
            return 0;
        }

        char t, d;
        tie(t, d) = query[i];
        if (d == 'L') {
            if (s[L + 1] == t) {
                L++;
            }
            if (s[R] == t) {
                R++;
            }
        } else {
            if (s[L] == t) {
                L--;
            }
            if (s[R - 1] == t) {
                R--;
            }
        }
    }
    cout << R - 1 - L << endl;

    return 0;
}