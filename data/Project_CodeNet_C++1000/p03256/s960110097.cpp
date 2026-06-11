#include <cstdio>
#include <cstdlib>
#include <queue>
#define maxn 200005

using namespace std;

struct node{
	int to, next;
}e[maxn << 1];
int head[maxn], tot = 0;
void addedge(int u, int v){e[++tot].to = v, e[tot].next = head[u]; head[u] = tot;}

int n, m, Index[maxn][2];
char str[maxn];

bool vis[maxn];

int topo(){
	queue <int> q; while (!q.empty()) q.pop();
	
	for (int i = 1; i <= n; i++)
		if (!Index[i][0] || !Index[i][1]) q.push(i), vis[i] = true;
	
	int cnt = 0;
	while (!q.empty()){
		int cur = q.front(); q.pop();
		cnt++;
		
		for (int i = head[cur]; i; i = e[i].next){
			if (!vis[e[i].to] && !(--Index[e[i].to][str[cur] - 'A'])){
				q.push(e[i].to);
				vis[e[i].to] = true;
			}
		}
	}
	return cnt;
	
}

int main(){
	scanf("%d%d%s", &n, &m, str + 1);
	
	while (m--){
		int u, v; scanf("%d%d", &u, &v);
		addedge(u, v);
		addedge(v, u);
		Index[v][str[u] - 'A']++;
		Index[u][str[v] - 'A']++;
	}
	
	puts(topo() == n ? "No" : "Yes");
	return 0;
}