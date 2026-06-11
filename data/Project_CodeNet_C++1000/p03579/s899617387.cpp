#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000

int main(){
	
	long long N,M;
	cin>>N>>M;
	
	vector<vector<int>> E(N,vector<int>());
	
	for(int i=0;i<M;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	
	vector<int> color(N,-1);
	queue<int> Q;
	Q.push(0);
	color[0] = 0;
	
	while(Q.size()!=0){
		int u = Q.front();
		Q.pop();
		for(int i=0;i<E[u].size();i++){
			int v = E[u][i];
			if(color[v]==-1){
				color[v]=color[u]^1;
				Q.push(v);
			}
			else{
				if(color[v]==color[u]){
					cout<<N*(N-1)/2 - M<<endl;
					return 0;
				}
			}
		}
	}
	
	vector<long long> c(2,0);
	
	for(int i=0;i<N;i++)c[color[i]]++;
	
	cout<<c[0]*c[1]-M<<endl;
	
	return 0;
}