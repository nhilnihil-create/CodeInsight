#include <algorithm>
#include <complex>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define REP(i, m, n) for (int i = int(m); i < int(n); i++)
#define RREP(i, m, n) for (int i = int(n) - 1; i >= int(m); --i)
#define EACH(i, c) for (auto &(i) : c)
#define all(c) begin(c), end(c)
#define EXIST(s, e) ((s).find(e) != (s).end())
#define SORT(c) sort(begin(c), end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
//#define int long long

#ifdef LOCAL
#define DEBUG(s) cout << (s) << endl
#define dump(x) cerr << #x << " = " << (x) << endl
#define BR cout << endl;
#else
#define DEBUG(s)                                                               \
    do {                                                                       \
    } while (0)
#define dump(x)                                                                \
    do {                                                                       \
    } while (0)
#define BR
#endif
using namespace std;

using UI = unsigned int;
using UL = unsigned long;
using LL = long long;
using ULL = unsigned long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VS = vector<string>;
using PII = pair<int, int>;
using VP = vector<PII>;

struct S {
    int s, t, c;
};

void solve() {
    int n, c;
    cin >> n >> c;
    vector<S> cs(n);
    REP(i, 0, n) cin >> cs[i].s >> cs[i].t >> cs[i].c;
    sort(all(cs), [](auto &l, auto &r) { return l.t < r.t; });
    vector<vector<S>> css(c);
    REP(i, 0, n) {
        int tc = cs[i].c;
        --tc;
        if (css[tc].size() > 0 && cs[i].s == css[tc].back().t) {
            css[tc].back().t = cs[i].t;
        } else {
            css[tc].push_back(cs[i]);
        }
    }
    VI imos(100000 + 1);
    REP(i, 0, c) {
        for (auto &s : css[i]) {
            imos[s.s]++;
            imos[s.t + 1]--;
        }
    }
    REP(i, 0, 100000) imos[i + 1] += imos[i];
    cout << *max_element(all(imos)) << endl;
}

signed main() {
    solve();

    return 0;
}