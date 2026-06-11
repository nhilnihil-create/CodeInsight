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
    int n, K;
    cin >> n >> K;

    vi vx, vy;
    vp v;

    rep(i, n) {
        int x, y;
        cin >> x >> y;

        vx.push_back(x);
        vy.push_back(y);
        v.push_back(mp(x, y));
    }

    sort(all(vx));
    sort(all(vy));

    int ans = 1ll << 62;

    rep(i, n) {
        int ax = vx[i];
        rep(j, n) {
            int ay = vy[j];
            for (int k = i + 1; k < n; ++k) {
                int bx = vx[k];
                for (int l = j + 1; l < n; ++l) {
                    int by = vy[l];
                    int res = 0;
                    D(ax); D(ay); D(bx); D(by);
                    rep(p, n) {
                        if (ax <= v[p].first && v[p].first <= bx && ay <= v[p].second && v[p].second <= by) ++res;
                    }
                    D(res);
                    if (res >= K) chmin(ans, (bx - ax) * (by - ay));
                }
            }
        }
    }

    cout << ans;
    
    return 0;
}
