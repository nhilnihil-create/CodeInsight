#include<bits/stdc++.h>
using namespace std;

const int MAX_N=1e5+10;
const int INF=1e9+10;

deque <pair<int,int> > Q;
int K;
vector <pair<int,int> > g[MAX_N];
int dist[MAX_N];

void get_dist(){
	for(int i=0;i<MAX_N;i++) dist[i]=INF;
	dist[1]=1;
	Q.push_back(make_pair(dist[1],1));
	while(Q.size()){
		int val=Q.front().first,x=Q.front().second;
		Q.pop_front();
		if(val>dist[x]) continue;
		for(int i=0;i<g[x].size();i++){
			int cost=g[x][i].first,to=g[x][i].second;
			if(dist[to]>dist[x]+cost){
				dist[to]=dist[x]+cost;
				if(cost==0)
					Q.push_front(make_pair(dist[to],to));
				else
					Q.push_back(make_pair(dist[to],to));
			}
		}
	}
}

int main(){
	scanf("%d",&K);
	for(int i=1;i<K;i++){
		g[i].push_back(make_pair(0,i*10%K));
		g[i].push_back(make_pair(1,(i+1)%K));
	}
	get_dist();
	printf("%d\n",dist[0]);
	return 0;
}