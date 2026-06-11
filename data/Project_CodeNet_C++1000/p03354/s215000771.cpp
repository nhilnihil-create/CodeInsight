#include <cmath>
#include <cstdio>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stdio.h>
#include <chrono>
using namespace std;

#define rep(i,s,n) for(ll i=s;i<(n);++i)
using ll = long long;
using pll = pair<ll, ll>;
constexpr ll INF = (1LL << 60);
constexpr ll MOD = (1e9 + 7);
//constexpr ll MOD = (998244353);

using vl = vector<ll>;
using vvl = vector<vector<ll>>;

template<class T>
vector<vector<T>> vvt(T init, ll m, ll n) {
	vector<vector<T>> ans = vector<vector<T>>(m, vector<T>(n, init));
	return move(ans);
}

template<class T>
vector<T> vt(T init,ll n) {
	vector<T> ans = vector<T>(n, init);
	return move(ans);
}

template<class T>
T maxVec(vector<T> &v) {
	T ans = -INF;
	rep(i,0, v.size()) {
		ans = max(ans, v[i]);
	}
	return ans;
}

// 素数判定
bool judge(ll n) {
	for (ll i = 2; i * i <= n; i++) if (n %= i)return false;
	return true;
}


template <class C>
void print(const C& c, std::ostream& os = std::cout)
{
	std::copy(std::begin(c), std::end(c), std::ostream_iterator<typename C::value_type>(os, ", "));
	os << std::endl;
}

ll count(ll n,ll r) {
	ll ans = 0,check = 1;
	rep(i,0, r) {
		if ((n & check) > 0) {
			ans++;
		}
		check = check << 1;
	}
	return ans;
}

ll gcd(ll a, ll b) {
	if (a < b) return gcd(b, a);
	ll r;
	while ((r = a % b)) {
		a = b;
		b = r;
	}
	return b;
}

class UnionFind {
public:
	vl parent;
	UnionFind(ll n) {
		parent = vl(n, -1);
	}

	ll root(ll n) {
		if (parent.at(n) < 0)return n;
		parent.at(n) = root(parent.at(n));
		return parent.at(n);
	}

	ll size(ll n) {
		return -parent.at(root(n));
	}

	bool connect(ll a, ll b) {
		if (root(a) == root(b))return false;
		a = root(a); b = root(b);
		if (size(a) < size(b))swap(a,b);
		parent[a] += parent[b];
		parent[b] = a;
		return true;
	}
};


int main() {
	ll n, m;
	cin >> n >> m;
	vl p(n, 0);
	rep(i, 0, n) {
		cin >> p[i];
	}
	UnionFind uni = UnionFind(n);
	rep(i, 0, m) {
		ll x, y;
		cin >> x >> y;
		uni.connect(x - 1, y - 1);
	}
	
	ll ans = 0;
	rep(i, 0, n) {
		if (uni.root(p[i] - 1) == uni.root(i))ans++;
	}
	printf("%lld\n", ans);
}