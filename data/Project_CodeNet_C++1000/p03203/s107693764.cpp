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
#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (ll)(x).size()
using namespace std;
using ll = long long;
constexpr ll INF = 3000000000000000000;

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<pair<int, int>> s(n);
    REP(i, n) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        s[i] = {x, y};
    }
    
    sort(ALL(s));
    int k = 0;
    REP(i, n) {
        if (s[i].second + k > s[i].first - 1) {
            if (s[i].second + k == s[i].first) ++k;
            continue;
        }
        cout << s[i].first << "\n";
        return 0;
    }
    cout << h << "\n";
    return 0;
    return 0;
}
