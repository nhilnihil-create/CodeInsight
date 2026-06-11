#ifdef LOCAL
#include "libs/debug/print_list.hpp"
#define debug(x) (cout << # x ": " << x << endl)
#define dev(v, m, n) for(int i=0;i<n;++i){for(int j=0;j<m;++j){cout<<"|"<<v[j][i];}cout<<"|"<<endl;}
#else
#define debug(x) ;
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
#include <vector>

using namespace std;

#define int long long int
#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(), (x).end()
#define capi(x) int x;cin>>x
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using vi = vector<int>;
using pi = pair<int, int>;
using vp = vector<pi>;

template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(b<a){a=b;return 1;}return 0;}

#define P (1'000'000'007)

signed main() {
    int a, b, q;
    cin >> a >> b >> q;

    set<int> s, t;

    rep(i, a) {
        capi(x);
        s.insert(x);
    }

    rep(i, b) {
        capi(x);
        t.insert(x);
    }

    rep(i, q) {
        capi(x);
        auto is = s.upper_bound(x);
        auto it = t.upper_bound(x);

        int res = 1ll << 61;
        if (is != s.end() && it != t.end()) {
            chmin(res, max(*is, *it) - x);
        }
        if (is != s.end() && it != t.begin()) {
            auto e = it;
            --e;
            int f = min(x - *e, *is - x);
            int g = max(x - *e, *is - x);
            chmin(res, f * 2 + g);
        }

        if (is != s.begin() && it != t.end()) {
            auto e = is;
            --e;
            int f = min(x - *e, *it - x);
            int g = max(x - *e, *it - x);
            chmin(res, f * 2 + g);
        }

        if (is != s.begin() && it != t.begin()) {
            --is; --it;
            chmin(res, x - min(*is, *it));
        }

        cout << res << endl;
    }
    
    return 0;
}
