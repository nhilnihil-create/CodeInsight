/* - - - - - - - - - - - - - - -
	User : 		VanishD
	problem :
	Points : 	
- - - - - - - - - - - - - - - */
# include <bits/stdc++.h>
# define 	ll 		long long
using namespace std;
const int inf = 0x3f3f3f3f, INF = 0x7fffffff;
const ll  infll = 0x3f3f3f3f3f3f3f3fll, INFll = 0x7fffffffffffffffll;
int read(){
	int tmp = 0, fh = 1; char ch = getchar();
	while (ch < '0' || ch > '9'){ if (ch == '-') fh = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9'){ tmp = tmp * 10 + ch - '0'; ch = getchar(); }
	return tmp * fh;
}
const int N = 200010;
struct Edge{
	int data, next;
}e[N * 2];
int use[N][2], head[N], flag, n, m, place;
char s[N];
void build(int u, int v){
	e[++place].data = v; e[place].next = head[u]; head[u] = place;
}
void dfs(int x, int tag){
	use[x][tag] = 1;
	for (int ed = head[x]; ed != 0; ed = e[ed].next){
		if (use[e[ed].data][tag ^ 1] == 2) continue;
		if (tag == 1){
			if (s[e[ed].data] == s[x]) continue;
			if (use[e[ed].data][0] == false)
				dfs(e[ed].data, 0);
				else flag = true;
		}
		else {
			if (s[e[ed].data] != s[x]) continue;
			if (use[e[ed].data][1] == false)
				dfs(e[ed].data, 1);
				else flag = true;
		}
	}
	use[x][tag] = 2;
}
int main(){
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = read(), m = read();
	scanf("\n%s", s + 1);
	for (int i = 1; i <= m; i++){
		int u = read(), v = read();
		build(u, v);
		build(v, u);
	}
	for (int i = 1; i <= n; i++){
		if (use[i][0] == 0) dfs(i, 0);
		if (use[i][1] == 0) dfs(i, 0); 
	}
	if (flag)
		printf("Yes\n");
		else printf("No\n");
	return 0;
}
