//nikkei2019qual_d.cpp
//Thu Jun  4 22:03:55 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
#define MOD 1000000007

using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	int n,m;
	cin >> n >> m;

	vector<int> g[n];
	set<int> par[n];
	for (int i=0;i<n-1+m;i++){
		int a,b;
		cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		par[b].insert(a);
	}

	int root = -1;
	for (int i=0;i<n;i++){
		if (par[i].size()==0){
			root = i;
			break;
		}
	}

	queue<int> q;
	q.push(root);
	int ans[n];
	fill(ans,ans+n,-1);
	while (!q.empty()){
		int tmp = q.front();q.pop();
		for (int i=0;i<g[tmp].size();i++){
			int next = g[tmp][i];
			if (par[next].size()>1){
				par[next].erase(tmp);
			}else{
				ans[next] = tmp;
				q.push(next);
			}
		}
	}

	for (int i=0;i<n;i++){
		cout << ans[i]+1 << endl;
	}

}