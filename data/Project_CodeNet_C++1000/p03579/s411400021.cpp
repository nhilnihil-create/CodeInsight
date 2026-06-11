#include<bits/stdc++.h>
#define EM 100000000
using namespace std;
using LL = long long;
using P = pair<LL, LL>;
LL LINF = 1e18;
int INF = 1e9;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using vLL = vector<LL>;
using vvLL = vector<vector<LL>>;

vint color(100010, 0);
vvint G(100010);
bool dfs(int v, int c){
	color[v] = c;
	for(auto g : G[v]){
		if(color[g] == c)	return false;
		if(color[g] == 0 && !dfs(g, -c))	return false;
	}
	return true;
}
int main(){
	LL N, M;
	cin >> N >> M;
	for(int i = 0;i < M;i++){
		int ai, bi;
		cin >> ai >> bi;
		G[ai-1].push_back(bi-1);
		G[bi-1].push_back(ai-1);
	}
	bool f = dfs(0, 1);
	LL r = 0, b = 0;
	for(int i = 0;i < N;i++){
		if(color[i] == 1)	r++;
		else 	b++;
	}

	if(f)	cout << (r*b-M) << endl;
	else 	cout << (N*(N-1)/2-M) << endl;
}