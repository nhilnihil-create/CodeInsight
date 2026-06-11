#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

constexpr ll infl = 10000000000000007LL;
constexpr int inf = 1000000007;

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    int sy, sx;
    cin >> sy >> sx;
    string s, t;
    cin >> s >> t;
    int l = 1, r = w, u = 1, d = h;
    for (int i = n - 1; i >= 0; --i) {
        if (t[i] == 'L')
            r = min(w, r + 1);
        else if (t[i] == 'R')
            l = max(1, l - 1);
        else if (t[i] == 'U')
            d = min(h, d + 1);
        else
            u = max(1, u - 1);

        if (s[i] == 'L')
            ++l;
        else if (s[i] == 'R')
            --r;
        else if (s[i] == 'U')
            ++u;
        else
            --d;

        if (l > r || u > d) {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (l <= sx && sx <= r && u <= sy && sy <= d)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}