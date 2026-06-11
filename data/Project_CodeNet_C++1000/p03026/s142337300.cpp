#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for (int (i) = 1; (i) <= (n); (i++))
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define yn {puts("Yes");}else {puts("No");}
#define printd(x) printf("%.12f\n", x);
template<class T> bool chmin(T& a, const T& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<vector<int>> g(10005);
vector<int> num(10005);
ll m;
vector<bool> visited(10005), visited2(10005);
vector<int> c(10005);

void bfs(int s) {
	queue<int> Q;
	Q.push(s);
	int cnt = 0;
	while (!Q.empty()) {
		int v = Q.front(); Q.pop();
		num[v] = c[cnt];
		cnt++;
		visited[v] = true;
		for (int to: g[v]) {
			if (visited[to]) continue;
			Q.push(to);
		}
	}
} 

void bfs2(int s) {
	queue<int> Q;
	Q.push(s);
	while (!Q.empty()) {
		int v = Q.front(); Q.pop();
		visited2[v] = true;
		for (int to: g[v]) {
			if (visited2[to]) continue;
			m += min(num[v], num[to]);
			Q.push(to);
		}
	}
}

int main() {
	int n;
	cin >> n;
	
	rep (i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	rep (i, n) cin >> c[i];

	sort(rrng(c));

	bfs(0);
	bfs2(0);

	cout << m << endl;
	rep (i, n) cout << num[i] << " ";
	cout << endl;
	return 0;
}