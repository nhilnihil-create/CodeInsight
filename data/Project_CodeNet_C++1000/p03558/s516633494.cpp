#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000


int main(){

	int K;
	cin>>K;
	
	vector<vector<pair<int,int>>> E(K,vector<pair<int,int>>());
	
	for(int i=0;i<K;i++){
		int a = (i*10)%K;
		E[i].emplace_back(a,0);
		int b = (i+1)%K;
		E[i].emplace_back(b,1);
	}
	
	vector<int> dis(K,Inf);
	dis[1] = 1;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
	Q.emplace(1,1);
	
	while(Q.size()!=0){
		int D1 = Q.top().first;
		int from = Q.top().second;
		Q.pop();
		if(D1!=dis[from])continue;
		for(int i=0;i<E[from].size();i++){
			int to = E[from][i].first;
			int D2 = E[from][i].second;
			if(dis[to]>D1+D2){
				dis[to] = D1+D2;
				Q.emplace(dis[to],to);
			}
		}
	}
	
	cout<<dis[0]<<endl;
	
    return 0;
}

