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


// With size

class UnionFind {
public:
    int uncon; 
    UnionFind(int n) {
        for (int i = 0; i < n; i++) {
            _parent.push_back(i);
            _size.push_back(1);
        }

        uncon = n * (n - 1) / 2;
    }

    int find(int index) {
        if (is_root(index)) return index;
        return _parent[index] = find(_parent[index]);
    }

    bool is_root(int index) {
        return _parent[index] == index;
    }

    bool has_same_root(int lhs, int rhs) {
        return find(lhs) == find(rhs);
    }

    void unite(int lhs, int rhs) {
        int l = find(lhs);
        int r = find(rhs);
        if (has_same_root(l, r)) return;
        int ls = _size[l]; int rs = _size[r];
        uncon -= (rs + ls) * (rs + ls - 1) / 2 - rs * (rs - 1) / 2 - ls * (ls - 1) / 2;
        _size[l] += rs;
        _parent[r] = l;
    }

    int size(int index) {
        return _size[find(index)];
    }

private:
    vector<int> _parent;
    vector<int> _size;
};

signed main() {
    int n, m;
    cin >> n >> m;

    vp vb;

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        --a; --b;

        vb.push_back(make_pair(a, b));
    }

    reverse(all(vb));

    vi ans;
    UnionFind uf(n);

    for (auto p: vb) {
        ans.push_back(uf.uncon);
        uf.unite(p.first, p.second);
    }

    reverse(all(ans));

    for (auto x: ans) {
        cout << x << endl;
    }
    
    return 0;
}
