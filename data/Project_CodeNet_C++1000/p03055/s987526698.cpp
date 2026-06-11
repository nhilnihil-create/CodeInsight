#include <bits/stdc++.h>
using namespace std;

#define N 200005

vector <int> v[N];

const int inf = 0x3f3f3f3f;
int d[N], p[N];

int BFS(int rt, int n) {
	static queue <int> Q;
	while (!Q.empty()) Q.pop();
	for (int i = 1; i <= n; i ++) d[i] = inf;
	d[rt] = p[rt] = 0;
	Q.push(rt);
	int res;
	while (!Q.empty()) {
		int x = Q.front(); Q.pop();
		res = x;
		for (int i = 0; i < v[x].size(); i ++) {
			int y = v[x][i];
			if (d[y] < inf) continue;
			d[y] = d[x] + 1; p[y] = x;
			Q.push(y);
		}
	}
	return res;
}

int main() {
	int n, x, y;
    scanf("%d", &n);
    for (int i = 1; i < n; i ++) {
		scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int k = BFS(1, n);
    k = BFS(k, n);
    puts(d[k]%3==1?"Second":"First");
	return 0;
}
