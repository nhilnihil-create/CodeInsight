#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	rep(i,n) cin >> v[i];
	map<int, int> even, odd;
	rep(i,n) {
		if (i % 2 == 0) even[v[i]]++;
		else odd[v[i]]++;
	}
	vector<pii> u, w;
	for (auto p: even) {
		u.push_back(pii(p.second, p.first));
	}
	for (auto p: odd) {
		w.push_back(pii(p.second, p.first));
	}
	sort(ALL(u), greater<>());
	sort(ALL(w), greater<>());

	if (u[0].second != w[0].second) {
		cout << n - u[0].first - w[0].first << endl;
	} else {
		int x = n - u[0].first - w[1].first;
		int y = n - u[1].first - w[0].first;
		cout << min(x, y) << endl;
	}
}

int main() {
	solve();
	return 0;
}