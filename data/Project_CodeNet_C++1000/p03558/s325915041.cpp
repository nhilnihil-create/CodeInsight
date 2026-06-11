/*
Problem : atcoder 084D
Algorithm : dijkstra
Status :
*/
#include <bits/stdc++.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

int n,len;
int head[MAXN],dis[MAXN],vis[MAXN];
priority_queue<pii,vector<pii>,greater<pii> > q;

struct Edge{
	int to,next,w;
} e[MAXN * 2];

void add(int u,int v,int w){
	e[++len].to = v;
	e[len].next = head[u];
	e[len].w = w;
	head[u] = len;
}

int main(){
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    memset(head,-1,sizeof(head));
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		add(i,(i + 1) % n,1);
		add(i,i * 10 % n,0);
		dis[i] = INF;
	}
	dis[1] = 1;
	q.push(make_pair(0,1));
	while(!q.empty()){
		int u = q.top().second;
		q.pop();
		if(vis[u])
		    continue;
		vis[u] = true;
		for(int i = head[u];i != -1;i = e[i].next){
			int v = e[i].to;
			if(dis[v] > dis[u] + e[i].w){
				dis[v] = dis[u] + e[i].w;
				q.push(make_pair(dis[v],v));
			}
		}
	}
	printf("%d\n",dis[0]);
	return 0;
}

