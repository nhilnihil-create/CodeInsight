#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <cassert>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr ll INF = 3000000000000000000;

int main() {
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    REP(i, n) {
        cin >> p[i];
        --p[i];
        q[p[i]] = i;
    }
    int x = 0, y = 1;
    for (int i = 1; i < n; ++i) {
        if (q[i - 1] < q[i]) {
            ++y;
        } else {
            x = max(x, y);
            y = 1;
        }
    }
    x = max(x, y);
    cout << n - x << "\n";
    return 0;
}
