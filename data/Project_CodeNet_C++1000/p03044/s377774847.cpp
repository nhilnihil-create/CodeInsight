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
using Graph = vector<vector<int>>;

template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(b<a){a=b;return 1;}return 0;}

#define P (1'000'000'007)

signed main() {
    int n;
    cin >> n;

    Graph g(n, vi());
    Graph ge(n, vi());

    rep(i, n - 1) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;

        if (w % 2 == 0) {
            ge[u].push_back(v);
            ge[v].push_back(u);
        } else {
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }

    vi vc(n, -1);

    queue<int> q;
    q.push(0);
    int p = 0;
    vc[0] = 0;

    while (!q.empty()) {
        auto x = q.front(); q.pop();

        for (auto v: g[x]) {
            if (vc[v] == -1) {
                vc[v] = 1 - vc[x];
                q.push(v);
            }
        }
        for (auto v: ge[x]) {
            if (vc[v] == -1) {
                vc[v] = vc[x];
                q.push(v);
            }
        }

        if (q.empty()) {
            while (++p < n) {
                if (vc[p] == -1) {
                    q.push(p);
                    vc[p] = 0;
                    break;
                }
            }
        }
    }

    for(auto c: vc) {
        cout << c << endl;
    }
    
    return 0;
}
