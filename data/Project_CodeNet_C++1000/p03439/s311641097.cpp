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

inline string gender(int x) {
    cout << x << endl;
    string t;
    cin >> t;
    return t;
}

int main() {
    int n;
    cin >> n;
    int l = 0, r = n - 1;
    string gender_l = gender(l);
    if (gender_l == "Vacant")
        return 0;
    string gender_r = gender(r);
    if (gender_r == "Vacant")
        return 0;

    while (r - l > 1) {
        int m = (l + r) / 2;
        string gender_m = gender(m);
        if (gender_m == "Vacant")
            return 0;

        int len = m - l + 1;
        if (len % 2 != 0) {
            if (gender_l == gender_m) {
                l = m;
                gender_l = gender_m;
            } else {
                r = m;
                gender_r = gender_m;
            }
        } else {
            if (gender_l == gender_m) {
                r = m;
                gender_r = gender_m;
            } else {
                l = m;
                gender_l = gender_m;
            }
        }
    }
    return 0;
}
