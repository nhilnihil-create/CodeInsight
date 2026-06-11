#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
using namespace std;
using ll = long long;
using P = pair<int ,int>;
const int INF = 1e9;
const int MOD = 1e9+7;

void print() { cout << endl; }
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) { cout << head << ((sizeof...(tail)!=0)?" ":""); print(forward<Tail>(tail)...); }
template <class T> void print(vector<T> &vec) { for (auto& a : vec) { cout << a << ((&a!=&vec.back())?" ":""); } cout << endl; }
template <class T> void print(vector<vector<T>> &df) { for (auto& vec : df) { print(vec); } }

struct UnionFind {
	vector<int> data;

	UnionFind(int sz) {
		data.assign(sz, -1);
	}

	void unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return;
		if (data[x] > data[y]) swap(x, y);
		data[x] += data[y];
		data[y] = x;
	}

	int find(int k) {
		if(data[k] < 0) return(k);
		return data[k] = find(data[k]);
	}

	bool same(int x, int y)	{
		return find(x) == find(y);
	}

	int size(int k)	{
		return -data[find(k)];
	}

    ll size2(int k)	{
		ll num = -data[find(k)];
        return num * (num-1ll) / 2ll;
	}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<P> edges(m);
    rep(i, m) {
        int x, y; cin >> x >> y;
        x--; y--;
        edges[i] = P(x, y);
    }

    UnionFind uf(n);

    reverse(all(edges));
    vector<ll> cnt(m+1);
    cnt[0] = 0;
    rep(i, m) {
        P p = edges[i];
        if (uf.same(p.fi, p.se)) cnt[i+1]=cnt[i];
        else {
            ll tmp = cnt[i];
            tmp -= uf.size2(p.fi);
            tmp -= uf.size2(p.se);
            uf.unite(p.fi, p.se);
            tmp += uf.size2(p.fi);
            cnt[i+1] = tmp;
        }
    }

    reverse(all(cnt));
    ll total = n * (n-1ll) / 2ll;
    FOR(i, 1, m+1) {
        cout << total-cnt[i] << endl;
    }
}