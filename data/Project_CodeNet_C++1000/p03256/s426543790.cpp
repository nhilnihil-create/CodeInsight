#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define enter putchar('\n')
#define space putchar(' ')
#define MAXN 200005
#define mo 994711
//#define ivorysi
using namespace std;
typedef unsigned long long int64;
typedef long double db;
typedef unsigned int u32;
template<class T>
void read(T &res) {
    res = 0;char c = getchar();T f = 1;
    while(c < '0' || c > '9') {
    	if(c == '-') f = -1;
    	c = getchar();
    }
    while(c >= '0' && c <= '9') {
    	res = res * 10 + c - '0';
    	c = getchar();
    }
    res *= f;
}
template<class T>
void out(T x) {
    if(x < 0) {putchar('-');x = -x;}
    if(x >= 10) out(x / 10);
    putchar('0' + x % 10);
}
struct node {
    int to,next;
}E[MAXN * 2];
int N,M,sumE,head[MAXN];
char s[MAXN];
int vis[MAXN][2];
void add(int u,int v) {
    E[++sumE].to = v;
    E[sumE].next = head[u];
    head[u] = sumE;
}
void Init() {
    read(N);read(M);
    scanf("%s",s + 1);
    int u,v;
    for(int i = 1 ; i <= M ; ++i) {
	read(u);read(v);add(u,v);add(v,u);
    }
}
bool dfs(int u,char c) {
    if(vis[u][c - 'A'] != -1) return vis[u][c - 'A'];
    vis[u][c - 'A'] = 0;
    for(int i = head[u] ; i ; i = E[i].next) {
	int v = E[i].to;
	if(c == s[v]) {
	    int t = (s[u] - 'A') ^ 1;
	    vis[u][c - 'A'] = 1;
	    bool f = dfs(v,'A' + t);
	    if(!f) {vis[u][c - 'A'] = 0;}
	    else break;
	}
    }
    return vis[u][c - 'A'];
}
void Solve() {
    memset(vis,-1,sizeof(vis));
    for(int i = 1 ; i <= N ; ++i) {
	if(dfs(i,'A') && dfs(i,'B')) {puts("Yes");return;}
    }
    puts("No");
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Init();
    Solve();
    return 0;
}
