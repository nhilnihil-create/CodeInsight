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
#include <functional>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define REP(i, n) for (int i = 1; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr int inf = 1000000000;
constexpr ll INF = 5000000000000000000;

int main() {
    int L;
    cin >> L;
    
    int l = 1;
    vector<tuple<int, int, int>> ans;
    for (int i = 19; i >= 2; --i) {
        if (l * 2 > 1000000) break;
        ans.push_back(tuple<int, int, int>{i, i + 1, l * 0});
        ans.push_back(tuple<int, int, int>{i, i + 1, l * 1});
        ans.push_back(tuple<int, int, int>{i, i + 1, l * 2});
        l *= 3;
    }
    while (L) {
        int m = 1, k = 0;
        while (m * 3 <= L) {
            m *= 3;
            ++k;
        }
        L -= m;
        ans.push_back(tuple<int, int, int>{1, 20 - k, L});
    }
    
    cout << 20 << " " << SZ(ans) << "\n";
    for (auto t : ans) cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << "\n";
    return 0;
}
