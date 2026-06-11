#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <math.h>
#include <deque>
#include <queue>
#include <map>
#include <iterator>
#include <set>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
#define rep(i,n) for(int i = 0; i < (n); i++)
template<typename T> void view(T e) { std::cout << e << std::endl; }
template<typename T> void view(const std::vector<T>& v) { for (const auto& e : v) { std::cout << e << " "; } std::cout << std::endl; }
template<typename T> void view(const std::vector<std::vector<T> >& vv) { for (const auto& v : vv) { view(v); } }
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

class UnionFind {
public:
    vector<ll> par;
    vector<ll> siz;

    UnionFind(ll k) :par(k), siz(k, 1LL) {
        rep(i, k) par[i] = i;
    }

    ll root(ll x) {
        if (par[x] == x) return x;
        else return par[x] = root(par[x]);
    }

    void unite(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return;

        if (siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return;
    }

    bool same(ll x, ll y) {
        return root(x) == root(y);
    }

    ll size(ll x) {
        return siz[root(x)];
    }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
    cin >> n >> m;
	vector<int> a(n);
	vector<P> v(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
    
    UnionFind uf(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        uf.unite(a, b);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (uf.same(i, a[i])) ans++;
    }
    cout << ans << endl;
}