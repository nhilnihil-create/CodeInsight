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
    int n, c;
    cin >> n >> c;

    vector<vector<int>> vd(c, vi());

    rep(i, c) {
        rep(j, c) {
            capi(x);
            vd[i].push_back(x);
        }
    }

    int m[3][30] = {0};

    rep(i, n) {
        rep (j, n) {
            capi(x); --x;

            ++m[(i + j) % 3][x];
        }
    }

    int ans = INT_MAX;

    rep(i, c) {
        for (int j = 0; j < c; ++j) {
            if (i == j) continue;
            for (int k = 0; k < c; ++k) {
                if (i == k || j == k) continue;
                int res = 0;
                rep(l, c) {
                    res += vd[l][i] * m[0][l];
                    res += vd[l][j] * m[1][l];
                    res += vd[l][k] * m[2][l];
                }

                chmin(ans, res);
            }
        }
    }

    cout << ans;

    return 0;
}
