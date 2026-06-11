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
    int n;
    cin >> n;
    vector<int> a(n);
    int max_abs = 0;
    int idx = -1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (abs(a[i]) >= abs(max_abs)) {
            max_abs = a[i];
            idx = i;
        }
    }
    cout << 2 * n - 1 << endl;
    for (int i = 0; i < n; ++i) {
        cout << idx + 1 << " " << i + 1 << endl;
    }

    if (max_abs >= 0) {
        for (int i = 0; i < n - 1; ++i) {
            cout << i + 1 << " " << i + 2 << endl;
        }
    } else {
        for (int i = n - 1; i >= 1; --i) {
            cout << i + 1 << " " << i << endl;
        }
    }
    return 0;
}