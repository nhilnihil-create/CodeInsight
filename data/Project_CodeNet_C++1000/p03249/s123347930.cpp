// Peace Of SHIT
#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> pii;
const int maxn = 1e5 + 5;
int n, si[maxn];
int sum = 0;
vector<int> e[maxn];
pii d[maxn];

void impossible() {
	cout << -1;
	exit(0);
}

void dfs(int u, int x) {
	sum += x;
	for(int i = 0; i < e[u].size(); i++) {
		dfs(e[u][i], x + 1);
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		d[i] = {a, i};
	}
	sort(d, d + n);
	reverse(d, d + n);
	
	vector <pii> k (d, d + n);
	
	for(int q = 0; q < n - 1; q++) {
		int leaf = d[q].second;
		int parD = d[q].first - (n - (2 * (si[leaf] + 1)));
		auto it = lower_bound(k.rbegin(), k.rend(), pii(parD, 0));
//		cout << "PAR : " <<it->first << " : " << parD << '\n';
		if(it -> first != parD) {
//			cerr << "AVALI\n";
			impossible();
		}
		int par = it -> second;
		si[par] += si[leaf] + 1;
		if((si[leaf] + 1) * 2 > n) {
//			cout << "DOVOMI\n";
			impossible();
		}
		//SEVOMI HAM MISHE D[I] ROOT OK E ?
		e[par].push_back(leaf);
	}
	int D = d[n - 1].second;
	dfs(D, 0);
	if(sum != d[n - 1].first)
		impossible();
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < e[i].size(); j++)
			cout << i + 1 << " " << e[i][j] + 1 <<'\n';
	}
	return 0;
}