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

    vector<int64_t> a(n);
    map<int64_t, int> s;
    rep(i, n)
    {
        cin >> a[i];
        s[a[i]]++;
    }

    sort(a.begin(), a.end());

    int result = 0;
    rrep(i, n)
    {
        if (s[a[i]] == 0) {
            continue;
        }
        int64_t b = a[i];
        b |= b >> 1;
        b |= b >> 2;
        b |= b >> 4;
        b |= b >> 8;
        b |= b >> 16;
        b |= b >> 32;
        b++;
        int64_t c = b - a[i];
        if ((c != a[i] && s[c] > 0) || (s[c] > 1)) {
            s[c]--;
            s[a[i]]--;
            result++;
            //cout << "a=" << a[i] << " c=" << c << endl;
        }
    }
    cout << result << endl;

    return 0;
}