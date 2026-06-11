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

constexpr ll infl = 10000000000000000LL;
constexpr int inf = 1000000000;

int main() {
    int n;
    cin >> n;
    vector<int> d(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    for (int i = 1; i < n + 1; ++i) {
        if ((i & 1) && d[i] != 0)
            d[i] = 24 - d[i];
    }
    int ans = inf;
    for (int i = 0; i < n + 1; ++i) {
        for (int j = i + 1; j < n + 1; ++j) {
            ans = min({ans, abs(d[i] - d[j]), 24 - abs(d[i] - d[j])});
        }
    }
    cout << ans << endl;
    return 0;
}