#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define mod 1000000007
#define mem(a,val) memset(a,val,sizeof(a))
#define ps(x,noOfDecimal) fixed<<setprecision(noOfDecimal)<<x

using namespace std;
void dfs(vector<int> arr[], vector<bool> &vis, int s) {

	vis[s] = true;
	// cout << s << " ";
	for (auto i : arr[s]) {
		if (!vis[i]) {
			dfs(arr, vis, i);
		}
	}

}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	std::ios::sync_with_stdio(false);
	int t = 1;
	// cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> arr[n];
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			a--;
			b--;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}

		vector<bool> vis(n, false);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				ans++;
				dfs(arr, vis, i);
				// cout << endl;
			}
		}
		cout << ans;
	}
	return 0;
}