#include<bits/stdc++.h>
using namespace std;
int k,dis[100000];
vector<vector<int> > v;
int main() {
	scanf("%d", &k);
	queue<int> q;
	int p = 1;
	for (int i = 0; i < k; i++) {
		while (!dis[p]) {
			dis[p] = 1;
			q.push(p);
			p = p * 10LL % k;
		}
	}
	if (dis[0]) {
		puts("1");
		return 0;
	}
	while (!q.empty()) {
		int h = q.front();
		q.pop();
		int t = (h + 1) % k;
		while (!dis[t]) {
			dis[t] = dis[h] + 1;
			q.push(t);
			t = t * 10LL % k;
		}
	}
	printf("%d", dis[0]);
	return 0;
}