#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

const int MAXN = 1e05 + 10;

int N;
pair<LL, int> d[MAXN];

int subsize[MAXN]= {0}, fa[MAXN]= {0};
void solve () {
	for (int i = N; i > 1; i --) {
		subsize[d[i].second] ++;
		int up = N - 2 * subsize[d[i].second];
		if (up < 0) { puts ("-1"); exit (0); }
		int p = lower_bound (d + 1, d + N + 1, make_pair (d[i].first - up, 0)) - d;
		if (p >= i || d[p].first != d[i].first - up) { puts ("-1"); exit (0); }
		fa[d[i].second] = d[p].second;
		subsize[d[p].second] += subsize[d[i].second];
	}
}

vector<int> G[MAXN];
LL dist[MAXN]= {0}, total = 0;
void DFS (int root) {
	total += dist[root];
	for (int i = 0; i < (int) G[root].size(); i ++) {
		int v = G[root][i];
		dist[v] = dist[root] + 1;
		DFS (v);
	}
}

inline LL getnum () {
	LL num = 0; char ch = getchar ();
	while (! isdigit (ch)) ch = getchar ();
	while (isdigit (ch)) num = (num << 3) + (num << 1) + ch - '0', ch = getchar ();
	return num;
}

int main () {
	// freopen ("33.txt", "r", stdin);

	N = getnum ();
	for (int i = 1; i <= N; i ++) d[i].first = getnum (), d[i].second = i;
	sort (d + 1, d + N + 1);
	solve ();
	for (int i = 2; i <= N; i ++) G[fa[d[i].second]].push_back(d[i].second);
	DFS (d[1].second);
	if (total != d[1].first) { puts ("-1"); return 0; }
	for (int i = 2; i <= N; i ++)
		printf ("%d %d\n", fa[d[i].second], d[i].second);

	return 0;
}

/*
7
10
15
13
18
11
14
19
*/

/*
2
1
2
*/