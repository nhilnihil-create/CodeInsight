#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
#define pii pair <int, int>
int k;
int dis[100005];
int dij() {
	priority_queue <pii, vector <pii>, greater <pii> > pq;
	memset(dis, inf, sizeof(dis));
	for (int i = 1; i <= 9; ++ i) pq.push(make_pair(dis[i] = i, i));
	while (!pq.empty()) {
		pii p = pq.top(); pq.pop();
		int v = p.second, d = p.first;
		for (int i = 0; i <= 9; ++ i) {
			int nw = (v * 10 + i) % k;
			if (dis[nw] > d + i) {
				dis[nw] = d + i;
				pq.push(make_pair(dis[nw], nw));
			}
		}
	}
	return dis[0];
}
int main() {
	scanf("%d", &k);
	printf("%d\n", dij());
	return 0;
}