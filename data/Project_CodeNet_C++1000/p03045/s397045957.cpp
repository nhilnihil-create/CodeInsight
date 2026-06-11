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

// With size

class UnionFind {
public:
    UnionFind(int n) {
        for (int i = 0; i < n; i++) {
            _parent.push_back(i);
            _size.push_back(1);
        }
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
        _size[l] += _size[r];
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

    UnionFind uf(n);

    int ans = n;

    rep(i, m) {
        int x, y, z;
        cin >> x >> y >> z;
        --x; --y;

        if (!uf.has_same_root(x, y)) {
            --ans;
            uf.unite(x, y);
        }
    }

    cout << ans;

    return 0;
}
