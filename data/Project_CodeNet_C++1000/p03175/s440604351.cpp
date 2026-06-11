// Problem : P - Independent Set
// Contest : AtCoder - Educational DP Contest
// URL : https://a...content-available-to-author-only...r.jp/contests/dp/tasks/dp_p?lang=en
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://g...content-available-to-author-only...b.com/cpeditor/cpeditor)

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define Ma7moud_7amdy                 \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define Open_Sesame Open()
#define all(v) ((v).begin()), ((v).end())
#define allr(v) ((v).rbegin()), ((v).rend())
#define clr(arr, x) memset(arr, x, sizeof arr)
#define endl "\n"
#define watch(x) cout << #x << " = " << x << endl;
#define RT(x) return cout << (x), 0;
#define Accepted 0
#define INF 0x3f3f3f3f3f3f3f3fLL
typedef long long ll;
typedef vector<int> vi;
const int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
void Open()
{
#ifndef ONLINE_JUDGE 
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif
}
const int mod = ll(1e9 + 7), N = 1e5 + 5;
//“Nobody but you have to believe in your dreams to make them a reality.” ― Germany Kent
int n;
vector<vector<int>>g;
int cnt = 0;
ll mem[N][2];
ll dfs(int node, int par, int lst) {
	ll& ret = mem[node][lst];
	if (~ret)return ret;
	ret = 1;
	for (int nxt : g[node]) {
		ll cur = 0;
		if (nxt != par) {
			cur += dfs(nxt, node, 0) % mod;
			if (lst != 1)
			{
				cur += dfs(nxt, node, 1) % mod;
			}
			ret *= cur % mod;
			ret %= mod;
		}
	}
	return ret;
}
int main()
{
	Ma7moud_7amdy;
	Open_Sesame;
	clr(mem, -1);
	cin >> n;
	g = vector<vector<int>>(n + 1);
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ll ans = dfs(1, -1, 1);
	ans += dfs(1, -1, 0);

	cout << ans %mod<< endl;
}
