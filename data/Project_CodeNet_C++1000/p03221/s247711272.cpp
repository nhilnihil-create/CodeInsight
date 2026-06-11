#include "bits/stdc++.h"
#include <set>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define all(i) (i).begin(), (i).end()
#define rall(i) (i).begin(), (i).end(), greater<int>()
#define int long long
#define elif else if
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define fst first
#define sec second
#define mod 1000000007
#define INF 10e10
template <typename T>

void print(T x)
{
	std::cout << x << " ";
}
template <typename T>

void println(T x)
{
	std::cout << x << "\n";
}

vector<int>yb[100001];

signed main(void) {
	int n, m;
	cin >> n >> m;
	vector<int>p(m);
	vector<int>y(m);
	rep(i, m) {
		cin >> p[i] >> y[i];
		yb[p[i]].pb(y[i]);

	}
	rep(i, n) {
		sort(yb[i+1].begin(), yb[i+1].end());
	}
	rep(i, m) {
		int x = lower_bound(yb[p[i]].begin(), yb[p[i]].end(), y[i]) - yb[p[i]].begin() + 1;
		printf("%012lld\n ", p[i]*1000000+x);
		println("");
	}
}