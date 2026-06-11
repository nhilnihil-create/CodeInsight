#include<bits/stdc++.h>

using namespace std;
using ll = long long;


vector<int> cost, c;
vector<vector<int>> hen;
void dfs(int v, int prev) {
	cost[v] = c.back();
	c.pop_back();

	for(auto i : hen[v]) {
		if(i == prev)continue;
		dfs(i, v);
	} 
}

int main()
{
	int n; cin >> n;
	cost.resize(n), hen.resize(n), c.resize(n);
	for(int i = 0; i < n - 1; i++) {int a, b; cin >> a >> b; a--, b--; hen[a].push_back(b), hen[b].push_back(a);}
	for(int i = 0; i < n ; i++)cin >> c[i];
	sort(c.begin(), c.end());
	cout << accumulate(c.begin(), c.end(), 0) - c.back() << endl;
	dfs(0, -1);
	for(int i = 0; i < n; i++)cout << cost[i] << " ";



}