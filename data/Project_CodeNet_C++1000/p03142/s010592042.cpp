#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>
#include <numeric>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
int INF = 1e9;
ll  LINF = 1e18;

bool seen[100005];
vector<vector<int>> G(100005,vector<int>());
vector<int> num;
void dfs(int v){
	if(!seen[v]){
		seen[v] = true;
		for(int nv:G[v]) dfs(nv);
		num.push_back(v);
	}
	return ;
}



int main(){
	int n,m;cin >> n >> m;
	vector<bool> root(n,false);
	rep(i,n+m-1){
		int a,b;cin >> a >> b;
		--a;--b;
		root[b] = true;
		G[a].push_back(b);
	}
	int r = 0;
	rep(i,n) seen[i] = false;
	rep(i,n) {
		if(!root[i]) {
			r = i;
			break;
		}
	}
	dfs(r);
	vector<int> pare(n);
	pare[r] = -1;
	for(int i = n-1;i >= 0;i--){
		for(int nv:G[num[i]]) pare[nv] = num[i];
	}
	rep(i,n) cout << pare[i]+1 << endl;


} 
