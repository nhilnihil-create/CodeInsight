#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000


int main(){
	
	int N,M;
	cin>>N>>M;
	
	string S;
	cin>>S;
	
	vector<vector<int>> cnt(N,vector<int>(2,0));
	vector<vector<int>> E(N,vector<int>());
	
	for(int i=0;i<M;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		
		E[a].push_back(b);
		E[b].push_back(a);
		if(S[b]=='A')cnt[a][0]++;
		else cnt[a][1]++;
		
		if(S[a]=='A')cnt[b][0]++;
		else cnt[b][1]++;
	}
	
	vector<bool> f(N,true);
	queue<int> Q;
	
	for(int i=0;i<N;i++){
		if(cnt[i][0]==0||cnt[i][1]==0){
			f[i]=false;
			Q.push(i);
		}
	}
	
	while(Q.size()!=0){
		int from = Q.front();
		Q.pop();
		for(int i=0;i<E[from].size();i++){
			int to = E[from][i];
			if(!f[to])continue;
			if(S[from]=='A'){
				cnt[to][0]--;
			}
			else{
				cnt[to][1]--;
			}
			if(cnt[to][0]==0||cnt[to][1]==0){
				f[to] = false;
				Q.push(to);
			}
		}
	}
	
	for(int i=0;i<N;i++){
		if(f[i]){
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	
	cout<<"No"<<endl;

	return 0;
}