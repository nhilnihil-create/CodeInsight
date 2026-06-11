#include<bits/stdc++.h>
using namespace std;

const int MAX_N=1e5+10;
const int INF=1e9+10;

int K,N,M,dist[MAX_N];
vector <pair<int,int> > g[MAX_N];
priority_queue <pair<int,int> > Q;

void get_dijk(){
	for(int i=0;i<MAX_N;i++) dist[i]=INF;
	dist[1]=1;
	Q.push(make_pair(-dist[1],1));
	while(Q.size()){
		int val=-Q.top().first,x=Q.top().second;
		Q.pop();
		if(dist[x]<val) continue;
		for(int i=0;i<g[x].size();i++){
			int cost=g[x][i].first,to=g[x][i].second;
			if(dist[to]>cost+dist[x]){
				dist[to]=cost+dist[x];
				Q.push(make_pair(-dist[to],to));
			}
		}
	}
}

int main(){
	cin>>K;
	for(int i=1;i<K;i++){
		g[i].push_back(make_pair(0,i*10%K));
		g[i].push_back(make_pair(1,(i+1)%K));
	}
	get_dijk();
	cout<<dist[0]<<endl;
	return 0;
}