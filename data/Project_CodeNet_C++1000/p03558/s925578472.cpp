#include<bits/stdc++.h>

using namespace std;

const int maxn=2e5+10;
int head[maxn],dis[maxn],vis[maxn],num;
struct Le
{
	int nt,to,dis;
}edge[maxn];

void add(int f,int t,int d){
	edge[++num].nt=head[f];
	edge[num].to=t;
	edge[num].dis=d;
	head[f]=num;
} 

int k;

void spfa(int s) {
	queue<int> q;
	memset(dis,0x3f,sizeof(dis));
	dis[s]=1;
	q.push(s);
	vis[s]=1;
	while(!q.empty()) {
		int u=q.front();
		q.pop();vis[u]=0;
		for(int i=head[u];i;i=edge[i].nt) {
			int v=edge[i].to;
			if(dis[v]>dis[u]+edge[i].dis) {
				dis[v]=dis[u]+edge[i].dis;
				if(!vis[v]) {
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
}

int main() {
	scanf("%d",&k);
	for(int i=0;i<k;++i) {
		add(i,(i+1)%k,1);
		add(i,i*10%k,0);
	}
	spfa(1);
	cout<<dis[0]<<"\n";
	return 0;
}
