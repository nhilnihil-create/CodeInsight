#include<bits/stdc++.h>
#define Rint register int
using namespace std;
typedef long long LL;
const int N = 100003;
int n, m, head[N], to[N << 1], nxt[N << 1];
LL ans;
inline void add(int a, int b){
	static int cnt = 0;
	to[++ cnt] = b; nxt[cnt] = head[a]; head[a] = cnt;
}
int tot, tot1, tot2, dep[N];
bool vis[N], flag;
inline void dfs(int x){
	vis[x] = true;
	tot1 += dep[x] & 1; ++ tot;
	for(Rint i = head[x];i;i = nxt[i])
		if(!vis[to[i]]){
			dep[to[i]] = dep[x] + 1;
			dfs(to[i]);
		} else flag |= !(dep[x] - dep[to[i]] & 1);
}
int main(){
	scanf("%d%d", &n, &m);
	for(Rint i = 1;i <= m;i ++){
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b); add(b, a);
	}
	for(Rint i = 1;i <= n;i ++)
		if(!vis[i]){
			tot = tot1 = flag = 0; dfs(i);
			if(flag) ans += (LL) tot * (tot - 1) / 2;
			else ans += (LL) tot1 * (tot - tot1);
		}
	printf("%lld", ans - m);
}