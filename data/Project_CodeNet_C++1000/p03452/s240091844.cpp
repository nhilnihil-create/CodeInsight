#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<numeric>

using namespace std;

int par[100000];
long long dist[100000];

void find(int x) {
	if (x != par[x]) {
		find(par[x]);
		dist[x] += dist[par[x]];
		par[x] = par[par[x]];
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m, l, r, lp, rp;
	long long d;
	cin >> n >> m;
	vector<int> rank(n, 0);
	for (int i = 0; i < n; i++) {
		par[i] = i;
		dist[i] = 0LL;
	}
	auto ans = "Yes";
	for (int i = 0; i < m; i++) {
		cin >> l >> r >> d;
		l--; r--;
		find(l); find(r);
		lp = par[l]; rp = par[r];
		if (lp == rp) {
			if (dist[r] - dist[l] != d) {
				ans = "No";
				break;
			}
		}
		else {
			if (rank[lp] < rank[rp]) {
				par[lp] = rp;
				dist[lp] = dist[r] - dist[l] - d;
			}
			else {
				par[rp] = lp;
				dist[rp] = dist[l] + d - dist[r];
				if (rank[lp] = rank[rp]) rank[lp]++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}