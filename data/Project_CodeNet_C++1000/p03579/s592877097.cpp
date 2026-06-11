#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int ll;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

vector<int> color;
vector<vector<int> > g;
void is_bipartite(int x){
	if(color[x] == 0){
		for(int i = 0; i < g[x].size(); i++){
			if(color[g[x][i]]<0){
				color[g[x][i]] = 1;
				is_bipartite(g[x][i]);
			}
		}
	}else{
		for(int i = 0; i < g[x].size(); i++){
			if(color[g[x][i]]<0){
				color[g[x][i]] = 0;
				is_bipartite(g[x][i]);
			}
		}
	}
}

int main()
{
	ll n,m;
	cin>>n>>m;
	g.resize(n,vector<int>());
	for(int i = 0; i < m; i++){
		int a,b;
		cin>>a>>b;
		g[a-1].push_back(b-1);
		g[b-1].push_back(a-1);
	}
	color.resize(n,-1);
	color[0] = 0;
	is_bipartite(0);
	bool flag = true;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < g[i].size(); j++){
			if(color[i] == color[g[i][j]]) flag = false;
		}
	}
	if(flag){
		ll left = 0,right = 0;
		for(int i = 0; i < n; i++){
			if(color[i]==0) left++;
			else if(color[i]==1) right++;
		}

	// 	for(int i = 0; i < n; i++){
	// 	cout << i << " " <<  color[i] << endl;
	// }

		// int cnt = 0;
		// for(int i = 0; i < n; i++){
		// 	if(color[i] == 0){
		// 		cnt += right - g[i].size();
		// 	}
		// }
		// cout << left << " " << right << endl;
		cout << left*right - m  <<endl;
	}else{
		// cout << "non-bipartite" << endl;
		cout << n*(n-1)/2 - m << endl;
	}


	return 0;
}