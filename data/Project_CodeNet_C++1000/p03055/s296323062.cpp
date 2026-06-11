#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 2e5 + 5;

vector<int> g[maxn];

int dp1[maxn], dp2[maxn], n;

void dfs(int u, int p){
	
	int mx = -1, smx = -1;
	for(auto &v : g[u]){
		if(v != p){
			dfs(v, u);
			dp1[u] = max(dp1[u], 1 + dp1[v]);
			
			if(dp1[v] >= mx){
				smx = mx;
				mx = dp1[v];
			}
			else if(dp1[v] >= smx)
				smx = dp1[v];
		}
	}
	
	if(mx != -1 && smx != -1)
		dp2[u] = 2 + mx + smx;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i = 1, a, b; i < n; i++){
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	dfs(1, 0);
	
	int diameter = 0;
	for(int i = 1; i <= n; i++){
		diameter = max(diameter, dp1[i]);
		diameter = max(diameter, dp2[i]);
	}
	
	int rem = diameter % 3;
	
	if(rem == 1)
		cout << "Second" << endl;
	else
		cout << "First" << endl;

	return 0;
}
