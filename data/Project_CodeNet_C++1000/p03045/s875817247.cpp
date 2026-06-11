#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define pb push_back
#define mk make_pair
const int siz = 1e5 + 7;
vector<int>par;
int getparent(int x) {
	if (par[x] == x)return x;
	return par[x] = getparent(par[x]);
}
void dsu(int a, int b) {
	a = getparent(a);
	b = getparent(b);
	if (a != b) {
		par[b] = a;
	}
}
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	par.resize(n + 1);
	for (int i = 0; i <= n; i++) {
		par[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int u, v, z;
		cin >> u >> v >> z;
		dsu(u, v);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (par[i] == i)ans++;
	}
	cout << ans << endl;
}
