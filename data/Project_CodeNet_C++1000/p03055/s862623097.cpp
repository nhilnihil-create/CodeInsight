#include<bits/stdc++.h>
#define Rint register int
using namespace std;
const int N = 200003;
int n, head[N], to[N << 1], nxt[N << 1];
inline void add(int a, int b){
	static int cnt = 0;
	to[++ cnt] = b; nxt[cnt] = head[a]; head[a] = cnt;
}
int now, ans, dep[N];
inline void dfs(int x, int f){
	for(Rint i = head[x];i;i = nxt[i])
		if(to[i] != f){
			dep[to[i]] = dep[x] + 1;
			dfs(to[i], x);
		}
}
int main(){
	scanf("%d", &n);
	for(Rint i = 1;i < n;i ++){
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b); add(b, a);
	}
	dfs(1, 0);
	for(Rint i = 1;i <= n;i ++)
		if(ans < dep[i]){
			ans = dep[i];
			now = i;
		}
	dep[now] = ans = 0;
	dfs(now, 0);
	for(Rint i = 1;i <= n;i ++)
		ans = max(ans, dep[i]);
	puts(ans % 3 == 1 ? "Second" : "First");
}