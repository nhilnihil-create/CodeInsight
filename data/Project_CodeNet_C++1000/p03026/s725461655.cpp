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
#define P pair<int,int>
vector<int> G[100010];
int c[100010];
int ans[100010];
int cnt;
int sum;
void dfs(int v, int parent) {
	ans[v] = c[cnt++];
	for (int to: G[v]) {
		if (to == parent) continue;
		sum += c[cnt];
		dfs(to, v);
	}
}
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for (int i = 0; i < N; i++) cin >> c[i];
	sort(c, c + N, greater<int>());
	P point = { 0,0 };
	for (int i = 0; i < N; i++) {
		point = max(point, { G[i].size(),i });
	}
	dfs(point.second, -1);
	cout << sum << endl;
	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}