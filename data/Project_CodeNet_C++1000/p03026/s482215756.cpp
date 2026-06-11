#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int n, m, k = 0;
vvi e;
vi c, d;
V<bool> seen;

void dfs(int v) {
	seen[v] = true;
	d[v] = c[k];
	k++;
	for (auto x : e[v])if (!seen[x])dfs(x);
	return;
}

int main() {


	cin >> n;

	e.resize(n);
	rep(i, n - 1) {
		int a, b;
		cin >> a >> b;a--;b--;
		e[a].emplace_back(b);
		e[b].emplace_back(a);
	}

	c.resize(n);
	rep(i, n)cin >> c[i];
	sort(all(c), greater<int>());
	
	ll m = 0;
	rep(i, n)m += c[i];
	m -= c[0];

	d.resize(n);
	seen.assign(n, false);
	dfs(0);
	
	cout << m << endl;
	rep(i, n) {
		cout << d[i];
		if (i != n - 1)cout << " ";
		else cout << endl;
	}	

}