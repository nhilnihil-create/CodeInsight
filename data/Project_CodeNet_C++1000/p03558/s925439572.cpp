#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
struct node{
	int pre, to, val;
}edge[200010];
int head[100010], tot;
int k;
void add(int u, int v, int l) {
	edge[++tot] = node{head[u], v, l};
	head[u] = tot;
}
int dis[100010], vis[100010];
queue<int> q;
void spfa() {
	memset(dis, 0x3f, sizeof(dis));
	dis[1] = 1;
	vis[1] = 1;
	q.push(1);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = head[x]; i; i = edge[i].pre) {
			int y = edge[i].to;
			if (dis[y] > dis[x] + edge[i].val) {
				dis[y] = dis[x] + edge[i].val;
				if (!vis[y]) {
					vis[y] = 1;
					q.push(y);
				}
			}
		}
		vis[x] = 0;
	}
}
int main() {
	cin >> k;
	for (int i = 0; i < k; i++) {
		add(i, (i + 1) % k, 1);
		add(i, i * 10 % k, 0);
	}
	spfa();
	cout << dis[0];
	return 0;
}