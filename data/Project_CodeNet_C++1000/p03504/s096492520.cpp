#ifdef LOCAL
#include "libs/debug/print_list.hpp"
#define D(x) (cout << # x ": " << x << endl)
#define dev(v, m, n) for(int i=0;i<n;++i){for(int j=0;j<m;++j){cout<<"|"<<v[j][i];}cout<<"|"<<endl;}
#else
#define D(x) ;
#define dev(v, m, n) ;
#endif

// :----------------------------------------

#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

#define int long long int
#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(), (x).end()
#define capi(x) int x;cin>>x
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mp(x, y) make_pair(x, y)

using vi = vector<int>;
using pi = pair<int, int>;
using vp = vector<pi>;
using Graph = vector<vector<int>>;

template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(b<a){a=b;return 1;}return 0;}

#define P (1'000'000'007)

signed main() {
    int n, C;
    cin >> n >> C;

    deque<pi> q[30];
    vector<tuple<int, int, int>> vt;
    
    rep(i, n) {
        int s, t, c;
        cin >> s >> t >> c;
        --c;
        vt.push_back(make_tuple(s, t, c));
    }

    sort(all(vt), [](const auto& lhs, const auto& rhs) { return get<0>(lhs) < get<0>(rhs); });

    for (auto x: vt) {
        auto s = get<0>(x);
        auto t = get<1>(x);
        auto c = get<2>(x);
        if (q[c].empty()) {
            q[c].push_front(mp(s, t));
        } else {
            if (s == q[c].back().second) {
                q[c].back().second = t;
            } else {
                q[c].push_back(mp(s, t));
            }
        }
    }

    vp v;

    rep(i, C) {
        for (auto x: q[i]) {
            v.push_back(x);
        }
    }


    sort(all(v), [](const auto& lhs, const auto& rhs){ return lhs.first < rhs.first; });

    multiset<int> ms;
    ms.insert(0);

    for (auto x: v) {
        bool f = true;
        for (auto it = ms.begin(); it != ms.end(); ++it) {
            if (*it < x.first) {
                ms.erase(it);
                ms.insert(x.second);
                f = false;
                break;
            }
        }

        if(f) ms.insert(x.second);
    }

    cout << ms.size();
    
    return 0;
}
