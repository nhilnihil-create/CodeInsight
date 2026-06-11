#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>

using namespace std;
using i64=long long int;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &e: a) cin >> e;

    int cur = 1;
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i-1]) {
            ans += cur / 2;
            cur = 1;
        } else {
            ++cur;
        }
    }
    ans += cur / 2;

    cout << ans << endl;

    return 0;
}
