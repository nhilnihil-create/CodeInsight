#pragma GCC optimize("Ofast")
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>

using namespace std;

#define ll long long
#define ull unsigned long long
const ll MOD = 1000000007;
#define rep(i,n) for (int i = 0; i < (n); ++i)

template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

struct UnionFind {
    vector<ll> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<ll> size;

    UnionFind(ll N) : par(N), size(N) { //最初は全てが根であるとして初期化
        for(ll i = 0; i < N; i++) par[i] = i;
        for(ll i = 0; i < N; i++) size[i] = 1LL;
    }

    ll root(ll x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    ll getSize(ll x) {
        return size[root(x)];
    }

    void unite(ll x, ll y) { // xとyの木を併合
        ll rx = root(x); //xの根をrx
        ll ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        // if (size[rx] > size[ry]) swap(rx, ry);
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
        size[ry] += size[rx];
    }

    bool same(ll x, ll y) { // 2つのデータx, yが属する木が同じならtrueを返す
        ll rx = root(x);
        ll ry = root(y);
        return rx == ry;
    }
};

int main() {
	ll N, M;
	cin >> N >> M;

	vector < pair<ll, ll> > edge;
	for (ll ii = 0; ii < M; ++ii){
		ll A, B;
		cin >> A >> B;
		A--; B--;
		edge.push_back(make_pair(A, B));
	}

	UnionFind tree(N);

	vector <ll> ans(M);
	ans[M-1] = N*(N-1)/2;

	for (int ii = M-1; ii > 0; --ii){
		ll A, B;
		A = edge[ii].first;
		B = edge[ii].second;

		if (tree.same(A, B)){
			ans[ii-1] = ans[ii];
		} else {
			ll sa = tree.getSize(A);
			ll sb = tree.getSize(B);
			ans[ii-1] = ans[ii] - sa*sb;
			tree.unite(A, B);
		}
	}

	for (int ii = 0; ii < M; ++ii){
		cout << ans[ii] << "\n";
	}

	return 0;
}
