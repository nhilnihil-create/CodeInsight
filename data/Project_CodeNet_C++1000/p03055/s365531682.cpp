#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

int n, point[200020], te = 0;
struct e {int to, next; } edge[400040];
void add (int a, int b) {
	te ++;
	edge[te].to = b;
	edge[te].next = point[a];
	point[a] = te;
}

int mx = 0, mx_id = 0;
int dis[200020];

void find_mx (int x) {
	// cerr << x << " " << dis[x] << endl;
	if (dis[x] > mx) {
		mx = dis[x], mx_id = x;
	}
	for (int e = point[x]; e; e = edge[e].next) {
		int to = edge[e].to;
		if (dis[to])
			continue ;
		dis[to] = dis[x] + 1;
		find_mx(to);
	}
}

int main() {
	cin >> n;
	for (int a, b, i = 1; i < n; i ++) {
		cin >> a >> b;
		add (a, b);
		add (b, a);
	}
	mx = 0;
	memset(dis, 0, sizeof dis);
	dis[1] = 1;
	find_mx(1);
	memset(dis, 0, sizeof dis);
	mx = 0;
	dis[mx_id] = 1;
	find_mx(mx_id);
	// cerr << mx << " mx" << endl;
	cout << (mx % 3 == 2 ? "Second" : "First") << endl;
	return 0;
}
