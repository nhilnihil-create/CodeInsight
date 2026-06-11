#include"bits/stdc++.h"
using namespace std;
#define int long long
#define con continue
#define rep(i,n) for(int i=0;i<n;i++)
const long long mod = 1000000007;
const long long inf = 1ll<<61;
typedef pair<int, int> P;
typedef pair<P, int> PP;
typedef pair<int, PP> PPP;
struct edge { int to; int to2; int cost; };

vector<int>G[200006];
int ae[200006], be[200006];
int used[200006];
signed main() {
	int n, m; cin >> n >> m;
	string s; cin >> s;
	rep(i, m) {
		int a, b; cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		if (a - b)G[b].push_back(a);
	}
	queue<int>Q;
	rep(i, n) {
		rep(j, G[i].size()) {
			if (s[G[i][j]] == 'A')ae[i]++;
			else be[i]++;
		}
		if (ae[i] == 0 || be[i] == 0)Q.push(i);
	}
	while (Q.size()) {
		int x = Q.front();
		Q.pop();
		if (used[x])continue;
		used[x]++;
		rep(i, G[x].size()) {
			if (s[x] == 'A')ae[G[x][i]]--;
			else be[G[x][i]]--;
			if (ae[G[x][i]] == 0 || be[G[x][i]] == 0)Q.push(G[x][i]);
		}
	}
	rep(i, n) {
		if (!used[i]) {
			puts("Yes"); return 0;
		}
	}
	puts("No");
}