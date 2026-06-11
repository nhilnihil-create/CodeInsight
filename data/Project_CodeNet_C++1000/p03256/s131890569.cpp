#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
 
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define forab(i, a, b) for(int i=(a);i<(b);++i)
#define foreach(i, n) for (__typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define sqr(x) ((x)*(x))
#define clr(a, b) memset(a, b, sizeof(a))
#define SZ(a) ((int)a.size())
#define inf 0x3f3f3f3f
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
const double eps = 1e-8;
int dcmp(double x) { if (x < -eps) return -1; else return x > eps;}
#define se(x) cout<<#x<<" = "<<x<<endl


#ifdef CHEN_PC
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
 
const int N = 200010;
const int M = 200010 * 2;
 
int n, m;
char s[N];
 
struct graph {
    int e, head[N];
    int ev[M], nxt[M];
	int vis[N];
	int del[N];
	int a[N];
	int b[N];
 
    void init() { e = 0; clr(head, -1); } 
    void addedge(int u, int v) {
        ev[e] = v; nxt[e] = head[u]; head[u] = e++;
    }
 
	void dfs(int u) {
		// printf("%d\n", u);
        vis[u] = 1;
        for (int i = head[u]; ~i; i = nxt[i]) { 
            int v = ev[i];
            if (!vis[v]) dfs(v);
			if (!del[v]) {
				if (s[v-1] == 'A') {
					a[u] = 1;
				} else {
					b[u] = 1;
				}
			}
			// printf("%d %d %d A%d B%d\n", u, v, del[v], a[u], b[u]);
        } 
		// printf("%d A%d B%d\n", u, a[u], b[u]);
		if (a[u] == 0 || b[u] == 0) {
			del[u] = 1;
		}
	}
 
	void handle(queue<int> &q1, queue<int> &q2, int mk) {
		while (!q1.empty()) {
			int u = q1.front(); q1.pop();
			// printf("%d\n", u);
        	for (int i = head[u]; ~i; i = nxt[i]) { 
            	int v = ev[i];
				if (del[v]) continue;
				if (s[v-1] == 'A') {
					a[u] = mk;
				} else {
					b[u] = mk;
				}
			}
			if (a[u] < mk || b[u] < mk) {
				debug("-- %d,\n", u);
				del[u] = 1;
        		for (int i = head[u]; ~i; i = nxt[i]) { 
            		int v = ev[i];
					if (del[v]) continue;
					q2.push(v);
				}
			}
		}
		// printf("[%d]\n", mk);
	}
 
	bool solve() {
		clr(vis, 0);
		clr(del, 0);
		clr(a, 0);
		clr(b, 0);
		int mk = 1;
		queue<int> q1, q2;
		forab (u, 1, n + 1) {
			q1.push(u);
		}
		while (true) {
			if (!q1.empty()) {
				handle(q1, q2, mk++);
			}
			if (!q2.empty()) {
				handle(q2, q1, mk++);
			}
			if (q1.empty()) {
				break;
			}
		}
		forab (i, 1, n + 1) {
			if (!del[i]) {
				return true;
			}
		}
		return false;
	}
 
};
 
 
int main(int argc, char *argv[]) {
#ifdef CHEN_PC
	freopen("C.in", "r", stdin);
#endif
	graph g;
	while (scanf("%d%d", &n, &m) != EOF) {
		scanf("%s", s);
		g.init();
		forn (i, m) {
			int a, b;
			scanf("%d%d", &a, &b);
			g.addedge(a, b);
			g.addedge(b, a);
		}
		bool ret = g.solve();
		if (ret) {
			puts("Yes");
		} else {
			puts("No");
		}
		// printf("%d\n", ret);
		// break;
	}
	return 0;
}