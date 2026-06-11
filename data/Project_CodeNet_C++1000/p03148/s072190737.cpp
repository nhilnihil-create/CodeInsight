#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <array>
#include <set>
#include <map>
#include <cmath>
#include <complex>
#include <algorithm>
#include <numeric>
#include <utility>
#include <tuple>
#include <bitset>
#include <cstdint>
#include <cassert>
#include <random>
#include <iterator>

using namespace std;
using i64 = int64_t;
using i32 = int32_t;

int main() {
    int n, k;
    cin >> n >> k;
    using P = pair<i64, i64>;
    vector<P> td(n);
    for (int i = 0; i < n; ++i) {
        i64 t, d;
        cin >> t >> d;
        td[i] = {t, d};
    }
    sort(begin(td), end(td), [](P p, P q) { return p.second < q.second; });
    vector<bool> ct(n + 1);
    i64 del = 0;
    i64 kin = 0;
    priority_queue<i64, vector<i64>, greater<i64>> que;
    for (int i = 0; i < k; ++i) {
        i64 t, d;
        tie(t, d) = td.back();
        td.pop_back();
        del += d;
        if (!ct[t]) {
            ct[t] = true;
            kin++;
        } else {
            que.push(d);
        }
    }
    i64 ans = del + kin * kin;
    while (!td.empty() && !que.empty()) {
        i64 t, d;
        tie(t, d) = td.back();
        td.pop_back();
        if (!ct[t]) {
            ct[t] = true;
            kin++;
            del -= que.top();
            que.pop();
            del += d;
            ans = max(ans, del + kin * kin);
        }
    }
    cout << ans << endl;
    return 0;
}