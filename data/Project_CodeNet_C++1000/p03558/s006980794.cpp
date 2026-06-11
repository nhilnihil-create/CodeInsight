#include<bits/stdc++.h>

using namespace std;

const int N = 1e6;

struct dartou{
	int to, nxt, w;
}e[N];

int k, cnt = 0;
int head[N], dis[N];
bool vis[N];

void add(int x, int y, int w){
	e[++cnt].to = y;
	e[cnt].w = w;
	e[cnt].nxt = head[x];
	head[x] = cnt;
}

void spfa(){
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	dis[1] = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for(int i = head[u]; i; i = e[i].nxt){
			int v = e[i].to, w = e[i].w;
			if(dis[u] + w < dis[v]){
				dis[v] = dis[u] + w;
				if(!vis[v]){
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
}

int main(){
	cin >> k;
	for(int i = 0; i < k; i++)
		add(i, (i + 1) % k, 1);
	for(int i = 0; i < k; i++)
		add(i, (i * 10) % k, 0);
	spfa();
	cout << dis[0] + 1 << endl;
}