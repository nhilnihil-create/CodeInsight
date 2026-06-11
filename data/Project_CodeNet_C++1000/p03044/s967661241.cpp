#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

struct edge {
	int to;
	ll cost;
};
vector<edge> G[100010];
int ans[100010];
void dfs(int v, int parent, ll dist) {
	ans[v] = dist % 2;
	for (int i = 0; i < G[v].size(); i++) {
		if (G[v][i].to == parent) continue;
		dfs(G[v][i].to, v, dist + G[v][i].cost);
	}
}
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		a--; b--;
		G[a].push_back({ b,c });
		G[b].push_back({ a,c });
	}
	dfs(0, -1, 0);
	for (int i = 0; i < N; i++) {
		cout << ans[i] << endl;
	}
}
