#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<int> ans, c;
int cur = 0;

void dfs(int v, int p, vector<vector<int>> &G){
	ans[v] = c[cur++];
	for(auto nv : G[v]){
		if(nv == p) continue;
		dfs(nv, v, G);
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> G(n);
	ans.resize(n);
	c.resize(n);
	int a, b;
	rep(i,n-1){
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	ll sum = 0;
	rep(i,n){
		cin >> c[i];
		sum += c[i];
	}
	sort(c.rbegin(), c.rend());
	cout << sum - c[0] << endl;
	dfs(0, -1, G);
	rep(i,n){
		cout << ans[i];
		if(i < n-1) cout << " ";
	}
	cout << endl;
	return 0;
}