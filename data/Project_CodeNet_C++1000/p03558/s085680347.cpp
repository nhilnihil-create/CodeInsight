#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>
#include<queue>
#define maxn 100000 
using namespace std;
int dist[maxn+5];
bool inq[maxn+5];
vector<pair<int,int> >E[maxn+5];
inline void add_edge(int u,int v,int w){
	E[u].push_back(make_pair(v,w));
}
int spfa(int s,int t){
	memset(dist,0x3f,sizeof(dist));
	queue<int>q;
	q.push(s);
	dist[s]=1;
	inq[s]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		inq[x]=0;
		for(auto p : E[x]){
			int w=p.second,y=p.first;
			if(dist[y]>dist[x]+w){
				dist[y]=dist[x]+w;
				if(!inq[y]){
					inq[y]=1;
					q.push(y);
				}
			}
		}
	}
	return dist[t];
}
int K;
int main(){

	scanf("%d",&K);
	for(int i=0;i<K;i++){
		add_edge(i,(i+1)%K,1);//如果没有进位,数位和+1 
		add_edge(i,i*10%K,0);
	}
	printf("%d\n",spfa(1,0));//从1到%K=0(实际上就是K) 
	
}
