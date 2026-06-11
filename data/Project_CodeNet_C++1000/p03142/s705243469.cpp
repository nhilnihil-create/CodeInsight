//nikkei2019qual_d_topo.cpp
//Thu Jun  4 23:20:50 2020

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
	int in[n];
	fill(in,in+n,0);
	int a[n-1+m],b[n-1+m];
	for (int i=0;i<n-1+m;i++){
		cin >> a[i] >> b[i];
		a[i]--;b[i]--;
		g[a[i]].push_back(b[i]);
		in[b[i]]++;
	}

	int root = -1;
	for (int i=0;i<n;i++){
		if (in[i]==0){
			root = i;
			break;
		}
	}

	queue<int> q;
	q.push(root);
	int dist[n];
	fill(dist,dist+n,0);
	while (!q.empty()){
		int tmp = q.front();q.pop();
		for (int i=0;i<g[tmp].size();i++){
			int next = g[tmp][i];
			in[next]--;
			dist[next] = max(dist[next],dist[tmp]+1);
			if (in[next]==0){
				q.push(next);
			}
		}
	}

	int par[n];
	fill(par,par+n,-1);
	for (int i=0;i<n-1+m;i++){
		if (dist[b[i]]-dist[a[i]]==1){
			par[b[i]] = a[i];
		}
	}

	for (int i=0;i<n;i++){
		cout << par[i]+1 << endl;
	}
}