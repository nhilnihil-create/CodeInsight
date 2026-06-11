#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cstring>
#include<string>
#include<cassert>
#include<cmath>
#include<climits>
#include<iomanip>
#include<bitset>
#include<unordered_map>

using namespace std;

#define rep(i,m,n) for(int (i)=(int)(m);(i)<(int)(n);(i)++)
#define rep2(i,m,n) for(int (i)=(int)(n)-1;(i)>=(int)(m);(i)--)
#define REP(i,n) rep(i,0,n)
#define REP2(i,n) rep2(i,0,n)
#define FOR(i,c) for(decltype((c).begin())i=(c).begin();i!=(c).end();++i)
#define ll long long
#define ull unsigned long long
#define all(hoge) (hoge).begin(),(hoge).end()
#define en '\n'
typedef pair<ll, ll> P;
constexpr long long INF = 1LL << 60;
constexpr int INF_INT = 1 << 25;
constexpr long long MOD = (ll)1e9+7;
typedef vector<ll> Array;
typedef vector<Array> Matrix;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;


template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

struct Edge {
	int to, cap, rev;
	Edge(int _to, int _cap, int _rev) {
		to = _to; cap = _cap; rev = _rev;
	}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void add_edge(Graph& G, int from, int to, int cap, bool revFlag, int revCap) {
	G[from].push_back(Edge(to, cap, G[to].size()));
	if (revFlag)G[to].push_back(Edge(from, revCap, G[from].size() - 1));
}

void solve() {
	ll n;
	cin >> n;
	if (n == 3) {
		cout << "2 5 63" << en;
		return;
	}

	cout << "2 3 4 9 ";
	n -= 4;

	ll k = 6;
	while (n >= 2 && k + 4<=30000) {
		cout << k + 2 << " " << k + 4<<" ";
		k += 6;
		n -= 2;
	}

	k = 15;
	while (n >= 2 && k+6 <= 30000) {
		cout << k << " " << k + 6 << " ";
		k += 12;
		n -= 2;
	}

	k = 6;
	while (n > 0) {
		cout << k<<" ";
		k += 6;
		n--;
	}
	cout << en;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solve();
	//int t; cin >> t; REP(i, t) solve();

	return 0;
}
