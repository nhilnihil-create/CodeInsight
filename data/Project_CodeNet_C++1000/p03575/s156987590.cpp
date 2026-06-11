#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <math.h>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <deque>
#include <queue>
#include <functional>
//#include <boost/multiprecision/cpp_int.hpp>

#define rep(i, n) for(int i = 0; i < n; ++i)
#define REP(i, m, n) for(int i = m; i < n; ++i)
#define rrep(i,n) for(int i = n; i >= 0; --i)
#define RREP(i, m, n) for(int i = n; i >= m; --i)
#define llrep(i, n) for(ll i = 0; i < n; ++i)
#define llREP(i, m, n) for(ll i = m; i < n; ++i)
#define llrrep(i,n) for(ll i = n; i >= 0; --i)
#define llRREP(i, m, n) for(ll i = n; i >= m; --i)

using ll = long long;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;
using pil = std::pair<int, long long>;
using pli = std::pair<long long, int>;
using plpii = std::pair<long long, std::pair<int, int>>;
using pdd = std::pair<double, double>;

const long long INF = 1000000000000000001;
const long long _MOD = 1000000007;
const long long MOD = 998244353;
const int ALPHABET = 27;
const double pi = 3.14159265358979;

using namespace std;
//namespace mp = boost::multiprecision;

class UnionFind {
private:
	int n;
	int* par;
	int* hight;

	int root(int a) {
		while (par[a] != a) a = par[a];
		return a;
	}
public:
	UnionFind(int num) {
		n = num;
		par = new int[n];
		hight = new int[n];
		for (int i = 0; i < n; ++i) {
			par[i] = i;
			hight[i] = 1;
		}
	}
	~UnionFind() {
		delete[] par;
	}

	void unite(int a, int b) {
		int ra = root(a);
		int rb = root(b);
		if (ra == rb) return;

		if (hight[ra] > hight[rb]) {
			par[rb] = ra;
		}
		else if (hight[ra] < hight[rb]) {
			par[ra] = rb;
		}
		else {
			par[ra] = rb;
			++hight[rb];
		}
	}
	bool same(int a, int b) {
		return root(a) == root(b);
	}

	int numofRoot() {
		int counter = 0;
		for (int i = 0; i < n; ++i) if (par[i] == i) ++counter;
		return counter;
	}

	void init() {
		for (int i = 0; i < n; ++i) {
			par[i] = i;
			hight[i] = 1;
		}
	}
};

using UF = UnionFind;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	pii* edge = new pii[m];
	rep(i, m) cin >> edge[i].first >> edge[i].second;

	int ans = 0;
	UF uf(n);
	rep(i, m) {
		rep(j, m) {
			if (i != j) uf.unite(edge[j].first - 1, edge[j].second - 1);
		}

		if (uf.numofRoot() != 1) {
			++ans;
		}

		uf.init();
	}

	cout << ans << "\n";

	return 0;
}

