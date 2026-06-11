#include<bits/stdc++.h>
using namespace std;
inline long long read () {
	long long num = 0;
	char c = ' ';
	bool flag = true;
	for (;c > '9' || c < '0';c = getchar())
		if (c == '-')
			flag = false;
	for (;c >= '0' && c <= '9';num = (num << 1) + (num << 3) + c - 48, c = getchar());
	return flag ? num : -num;
}
namespace graph {
	const int maxn = 100020;
	struct node {
		int y, next;
	} a[maxn << 1];
	int head[maxn], top = 0;
	void insert (int x, int y) {
		a[top].y = y;
		a[top].next = head[x];
		head[x] = top ++;
	}
} using namespace graph;

namespace INIT {
	map <long long, int> m;
	int n; long long d[maxn];
	void init () {
		n = read ();
		for (int i = 1;i <= n;i ++) {
			d[i] = read ();
			m[d[i]] = i;
		}
		sort (d + 1,d + 1 + n);
	}
} using namespace INIT;

namespace WORK {
	int size[maxn];
	void work () {
		memset (head, -1, sizeof head);
		for (int i = 1;i <= n;i ++)
			size[i] = 1;
		for (int i = n;i > 1;i --) {
			int x = m[d[i]];
			long long t = n - 2 * size[x];
			t = d[i] - t;
			/*if (m.count(t) == 0) {
				printf ("-1\n");
				exit (0);
			}*/
			int y = m[t];
			insert (y, x);
			insert (x, y);
			size[y] += size[x];
		}
	}
} using namespace WORK;

namespace CHECK {
	int dis[maxn];
	void dfs (int x, int fa) {
		for (int i = head[x];i + 1;i = a[i].next) {
			int y = a[i].y;
			if (y == fa) continue;
			dis[y] = dis[x] + 1;
			dfs (y, x);
		}
	}
	void check () {
		dfs (m[d[1]], -1);
		long long s = 0;
		for (int i = 1;i <= n;i ++)
			s += dis[i];
		if (s != d[1]) printf ("-1\n");
		else for (int i = 0;i < top;i += 2) 
				printf ("%d %d\n",a[i].y, a[i ^ 1].y);
	}
} using namespace CHECK;
int main () {
	init ();
	work ();
	check ();
	return 0;
}