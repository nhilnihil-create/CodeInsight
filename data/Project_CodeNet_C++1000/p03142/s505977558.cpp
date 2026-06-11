#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000



int main(){
	
	int N,M;
	cin>>N>>M;
	
	vector<vector<int>> E(N,vector<int>());
	vector<vector<int>> p = E;
	vector<int> cnt(N,0);
	
	for(int i=0;i<N+M-1;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		cnt[v] ++;
		E[u].push_back(v);
		p[v].push_back(u);
	}
	
	queue<int> Q;
	vector<int> sorted;
	
	for(int i=0;i<N;i++){
		if(cnt[i]==0){
			Q.push(i);
			sorted.push_back(i);
		}
	}
	
	while(Q.size()!=0){
		int u = Q.front();
		Q.pop();
		for(int i=0;i<E[u].size();i++){
			int v = E[u][i];
			cnt[v]--;
			if(cnt[v]==0){
				Q.push(v);
				sorted.push_back(v);
			}
		}
	}
	
	vector<int> ind(N);
	for(int i=0;i<N;i++){
		ind[sorted[i]]=i;
	}
	
	vector<int> ans(N);
	for(int i=0;i<N;i++){
		int id = -1;
		int maxi = -1;
		for(int j=0;j<p[i].size();j++){
			int v = p[i][j];
			if(ind[v]>maxi){
				maxi = ind[v];
				id = v;
			}
		}
		ans[i] = id;
	}
	
	for(int i=0;i<N;i++){
		cout<<ans[i]+1<<endl;
	}
	
	
	
	return 0;
}