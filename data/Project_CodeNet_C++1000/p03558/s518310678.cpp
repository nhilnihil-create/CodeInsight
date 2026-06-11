#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cctype>
#include<queue>
#include<vector>
inline int read() {
	int x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) f ^= c == '-';
	for (; isdigit(c); c = getchar())  x = x * 10 + c - '0';
	return f ? x : -x;
}
using namespace std;
const int yuzu = 1e5;
int d[yuzu | 10],k;

void bfs(int u, int dep) {
	memset(d, 0x3f, sizeof d);
	queue<int> q;
	q.push(1), d[1] = 1;
	for (; !q.empty();) {
		int u = q.front();q.pop();
		int net = u * 10 % k;
		if (d[net] > d[u]) {
			q.push(net);
			d[net] = d[u];
		}
		net = (u + 1) % k;
		if (d[net] > d[u] + 1) {
			q.push(net);
			d[net] = d[u] + 1;
		}
	}
}

int main() {
	k = read();
	bfs(1, 1);
	cout << d[0]<<endl;
}