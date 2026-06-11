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

class UnionFind {
public:
    UnionFind(int n) {
        for (int i = 0; i < n; i++) parent.push_back(i);
    }

    int find(int index) {
        if (is_root(index)) return index;
        return parent[index] = find(parent[index]);
    }

    bool is_root(int index) {
        return parent[index] == index;
    }

    bool has_same_root(int lhs, int rhs) {
        return find(lhs) == find(rhs);
    }

    void unite(int lhs, int rhs) {
        int l = find(lhs);
        int r = find(rhs);
        if (has_same_root(l, r)) return;
        parent[r] = l;
    }

private:
    vector<int> parent;
};

signed main() {
    int n, m;
    cin >> n >> m;

    vi va(n, -1);

    rep(i, n) {
        capi(p); --p;
        va[p] = i;
    }

    UnionFind uf(n);

    rep(i, m) {
        int x, y;
        cin >> x >> y;
        --x; --y;

        uf.unite(x, y);
    }

    int ans = 0;

    rep(i, n) {
        if (uf.has_same_root(i, va[i])) {
            ++ans;
        } 
    }

    cout << ans;

    return 0;
}
