#include <iostream>
#include <algorithm>
#include <cstdio>
#include <regex>
#include <cmath>
#include <vector>
#include <queue>
#include <functional>
#include <numeric>
#include <iomanip>
#include <stack>
#include <string>
#include <map>
#include <set>
#define REP(i, n) for(int i = 0;i < n; i++)
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
const long long INF = INT64_MAX;

// 重み付きUnionFind
class WeightedUF {
public:
    ll tsize;
    ll mode;
    vector<ll> par;
    vector<ll> rank;
    vector<ll> w;
    WeightedUF() {}
    WeightedUF(const WeightedUF &wuft) {}
    WeightedUF(ll n, ll m = 0) {
        tsize = n;
        mode = m;
        par.resize(n, -1);
        if(!mode) rank.resize(n, 0);
        w.resize(n, 0);
    }
    ll root(ll x) {
        if(par[x] < 0) {
            return x;
        }else {
            ll r = root(par[x]);
            w[x] += w[par[x]];
            return par[x] = r;
        }
    }
    ll weight(ll x) {
        root(x);
        return w[x];
    }
    ll diff(ll x, ll y) {
        return weight(y) - weight(x);
    }
    bool isRoot(ll x) {
        return root(x) == x;
    }
    bool isSame(ll x, ll y) {
        return root(x) == root(y);
    }
    void unite(ll x, ll y, ll _w) {
        _w += weight(x);
        _w -= weight(y);
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(mode) {
            par[x] += par[y];
            par[y] = x;
        }else {
            if(rank[x] < rank[y]) {
                par[y] += par[x];
                par[x] = y;
                w[x] = -_w;
            }else {
                par[x] += par[y];
                par[y] = x;
                if(rank[x] == rank[y]) rank[x]++;
                w[y] = _w;
            }
        }
    }
    ll size(ll x) {
        return -par[root(x)];
    }
};

int main() {
    ll N, M;
    cin >> N >> M;
    vll L(M), R(M), D(M);
    for(int i = 0; i < M; i++)
    {
        cin >> L[i] >> R[i] >> D[i];
    }
    WeightedUF uf(N);
    for(int i = 0; i < M; i++)
    {
        if(uf.isSame(L[i]-1, R[i]-1)) {
            if(uf.diff(L[i]-1, R[i]-1) != D[i]) {
                cout << "No" << endl;
                return 0;
            }
        }else {
            uf.unite(L[i]-1, R[i]-1, D[i]);
        }
    }
    cout << "Yes" << endl;
    return 0;
}