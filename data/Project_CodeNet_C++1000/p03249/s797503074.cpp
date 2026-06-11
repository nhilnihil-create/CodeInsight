#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

#ifdef BTK
#define DEBUG if(1)
#else
#define CIN_ONLY if(1)
struct cww {cww() {CIN_ONLY{ios::sync_with_stdio(false); cin.tie(0);}}
}star;
#define DEBUG if(0)
#endif

#define ALL(v) (v).begin(),(v).end()
#define REC(ret, ...) std::function<ret (__VA_ARGS__)>
template <typename T>inline bool chmin(T &l, T r){bool a = l>r; if (a)l = r; return a;}
template <typename T>inline bool chmax(T &l, T r){bool a = l<r; if (a)l = r; return a;}
template <typename T>istream& operator>>(istream &is, vector<T> &v){for (auto &it : v)is >> it;return is;}

class range {private: struct I { int x; int operator*() { return x; }bool operator!=(I& lhs) { return x<lhs.x; }void operator++() { ++x; } }; I i, n;public:range(int n) :i({ 0 }), n({ n }) {}range(int i, int n) :i({ i }), n({ n }) {}I& begin() { return i; }I& end() { return n; }};

int n;

int a[112345];
int b[112345];
pair<LL,int> d[112345];
int sub[112345];
vector<vector<int>> g;
pair<LL,int> f(int v,int p) {
	pair<LL, int> ret = { 0ll,1 };
	for (int u : g[v]) {
		if (p == u)continue;
		auto cret=f(u, v);
		ret.first += cret.first;
		ret.second += cret.second;
	}
	ret.first += ret.second;
	return ret;
}
bool check() {
	g.resize(n);
	for (int i : range(n - 1)) {
		g[a[i]].push_back(b[i]);
		g[b[i]].push_back(a[i]);

	}
	LL A = f(0, 0).first - n;
	LL B = d[0].first;
	return A == B;
}
int main() {
	cin >> n;
	
	for (int i : range(n)) {
		cin >> d[i].first;
		d[i].second = i + 1;
	}
	sort(d, d + n);
	reverse(d, d + n);
	for (int i : range(n))sub[i] = 1;
	map<LL, int> id;
	for (int i : range(n))id[d[i].first] = i;
	for (int i : range(n - 1)) {
		LL k = sub[i];
		LL rest = n - sub[i];
		LL nxt_dist = d[i].first + k - rest;
		if (id.count(nxt_dist) == 0) {
			cout << -1 << endl;
			return 0;
		}
		int j = id[nxt_dist];
		a[i] = i;
		b[i] = j;
		sub[j] += sub[i];
	}

	if (check()) {
		for (int i : range(n - 1)) {
			cout << d[a[i]].second << " " << d[b[i]].second << endl;
		}
	}
	else {
		cout << -1 << endl;
	}
	return 0;
}
