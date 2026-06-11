#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5+10;
const int mod = 1e9+7;

vector<int> g[N];

ll w[N], b[N];

void dfs(int v, int p) {
	//bool f = 1;
	w[v] = b[v] = 1;
	for(auto i: g[v]) {
		if(i==p) continue;
		else {
			dfs(i, v);
			w[v] *= (w[i]+b[i]);
			b[v] *= w[i];
			w[v] %= mod;
			b[v] %= mod;
			//f = 0;
		}
	}

	// if(f) {
	// 	w[v] = b[v] = 1;
	// }
	
	w[v] %= mod;
	b[v] %= mod;
}

int main() {
	int n;
	cin >> n;

	for(int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;

		g[x].push_back(y);
		g[y].push_back(x);
	}

	dfs(1, -1);
	// int sum = 0;
	// for(int i = 1; i <= n; i++) {
	// 	cout << i << "=i " << w[i] << " " << b[i] << endl;
	// 	sum += (w[i]+b[i]);
	// }
	// cout << sum << endl;
	cout << (w[1]+b[1])%mod;
}