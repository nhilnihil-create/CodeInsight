#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctype.h>
#include <algorithm>
#include <fstream>
#include <set>
#define mp make_pair
#define Debug(...) fprintf(stdout, __VA_ARGS__)

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, int> pli;
typedef set<pli>::reverse_iterator sit;

const int MAXN = 1e5 + 7;

inline void proc_status() {
	ifstream t("/proc/self/status");
	cerr << string(istreambuf_iterator<char>(t), istreambuf_iterator<char>()) << endl;
}

template<typename T> inline T read() {
	T res = 0, flag = 1; char in = getchar();
	while(!isdigit(in)) { if(in == '-') flag = -1; in = getchar(); }
	while(isdigit(in)) { res = (res << 1) + (res << 3) + in - '0'; in = getchar(); }
	return res * flag;
}

template<typename T> inline void chkmax(T &a, T b) { if(a < b) a = b; }
template<typename T> inline void chkmin(T &a, T b) { if(a > b) a = b; }

int n, rt;
set<pli> D;

int f[MAXN], siz[MAXN];
LL dis[MAXN], sum[MAXN];
bool vis[MAXN];
int dex, head[MAXN], to[MAXN], nxt[MAXN];

inline void Link(int x, int y) { nxt[++dex] = head[x]; to[dex] = y; head[x] = dex; }

void dfs(int u) {
	vis[u] = 1;
	for(int i = head[u]; i; i = nxt[i]) {
		int v = to[i];
		if(vis[v]) { puts("-1"); exit(0); }
		dfs(v);
		sum[u] += sum[v] + siz[v];
	}
}

inline void init() {
	n = read<int>();
	for(int i = 1; i <= n; ++i) {
		D.insert(mp(read<LL>(), i));
	}
	rt = (*D.begin()).second;
}

inline void solve() {
	int cnt = 0;
	for(sit it = D.rbegin(); it != D.rend(); ++it) {
		int u = (*it).second;
		dis[u] = (*it).first;
		++siz[u];
		if(u == rt) break;
		LL nxt = dis[u] + (siz[u] << 1) - n;
		pli fa = (*D.lower_bound(mp(nxt, 0)));
		if(fa.first == nxt) {
//			printf("%d %d\n", fa.second, u);
//			printf("Linked\n\n");
			f[u] = fa.second;
			Link(f[u], u);
			siz[f[u]] += siz[u];
		}
//		if(siz[f[u]] == n) { rt = f[u]; break; }
	}

//	cout << rt << endl;
//	exit(0);
	dfs(rt);
	if(dis[rt] != sum[rt]) {
		puts("-1");
		exit(0);
	}
	for(int i = 1; i <= n; ++i) if(i != rt) {
		printf("%d %d\n", i, f[i]);
	}
}

int main() {

	init();
	solve();

	return 0;
}

