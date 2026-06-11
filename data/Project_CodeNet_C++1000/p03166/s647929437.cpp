/***  بسم الله الرحمن ا لرحيم   ***/
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_map>
#define endl                         '\n'
#define Ceil(x,y)             ((x+y-1)/y)
#define sz(s)               (int)s.size()
#define RT(x)           return cout<<x,0;
#define mem(x,y)    memset(x,y,sizeof(x))
#define all(v) ((v).begin()), ((v).end())
#define watch(x) cout<<#x<<" = { "<<x<<" }\n"
#define test int t;cin>>t;while(t--)
const int dx[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
const int dy[] = { 1, 0, -1, 0, 1, -1, 1, -1 };
const double PI = acos(-1), EPS = 1e-7;
const int OO = 0x3f3f3f3f, N = 2e5 + 5, mod = 1e9 + 7;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll x, ll y) { return (!y) ? x : gcd(y, x % y); }
ll lcm(ll x, ll y) { return ((x / gcd(x, y)) * y); }
void file() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif  !ONLINEJUDGE
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

int n,m;
vector<vector<int>>g;
int vis[N];
int dfs(int u) {
	if (vis[u] == -1) {
		vis[u] = 0;
		for (auto t : g[u]) {
			vis[u] = max(vis[u], dfs(t) + 1);
		}
	}
	return vis[u];

}
void solve() {
	cin >> n >> m;
	g = vector<vector<int>>(n + 1);
	int x, y; 
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		g[x].push_back(y);
	}
	mem(vis, -1);
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		mx = max(mx, dfs(i));
	}
	cout << mx;

}
int main() {
	file();
   
      solve();
    

	return 0;
}