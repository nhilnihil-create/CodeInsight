#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <deque>
#define N 101000
template<typename T> inline void read(T &x) {
	x = 0; char c = getchar(); bool flag = false;
	while (!isdigit(c)) {if (c == '-') flag = true; c = getchar(); }
	while (isdigit(c)) {x = (x << 1) + (x << 3) + (c ^ 48); c = getchar(); }
	if (flag)	x = -x;
}
using namespace std;
int n;
int dis[N];
deque<int> q, qq;
inline void bfs() {
	q.push_back(1);
	qq.push_back(1);
	while (q.size()) {
		int p = q.front();
		q.pop_front();
		int v = qq.front();
		qq.pop_front();
		if (dis[p])	continue;
		dis[p] = v;
		if (!p)	return ;
		q.push_back((p + 1) % n);
		qq.push_back(dis[p] + 1);
		q.push_front(p * 10 % n);
		qq.push_front(dis[p]);
	}
}

int main() {
	read(n);
	bfs();
	printf("%d\n", dis[0]);
	return 0;
}
/*
6 3
41 5
79992 36
7 2(1001)
*/