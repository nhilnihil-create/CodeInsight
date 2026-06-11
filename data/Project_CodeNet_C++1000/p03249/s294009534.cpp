#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define enter putchar('\n')
#define space putchar(' ')
//#define ivorysi
#define MAXN 100005
typedef long long int64;
using namespace std;
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
	if(x < 0) {x = -x;putchar('-');}
	if(x >= 10) {
		out(x / 10);
	}
	putchar('0' + x % 10);
}
int N;
int64 D[MAXN],L[MAXN],dep[MAXN],C[MAXN];
int id[MAXN],s[MAXN],t[MAXN],tot,siz[MAXN];

struct node {
    int to,next;
}E[MAXN * 2];
int head[MAXN],sumE;
void add(int u,int v) {
    E[++sumE].to = v;
    E[sumE].next = head[u];
    head[u] = sumE;
}
bool cmp(int a,int b) {
    return D[a] < D[b];
}
void dfs(int u,int fa) {
    siz[u] = 1;
    for(int i = head[u] ; i ; i = E[i].next) {
        int v = E[i].to;
        if(v != fa){
            dep[v] = dep[u] + 1;
            dfs(v,u);
            siz[u] += siz[v];
        }
    }
}
bool dfs1(int u,int fa) {
    if(C[u] != D[u]) return false;
    for(int i = head[u] ; i ; i = E[i].next) {
        int v = E[i].to;
        if(v != fa) {
            C[v] = C[u] - siz[v] + N - siz[v];
            if(!dfs1(v,u)) return false;
        }
    }
    return true;
}
void Solve() {
    read(N);
    for(int i = 1 ; i <= N ; ++i) {
        read(D[i]);id[i] = i;siz[i] = 1;
    }
    sort(id + 1,id + N + 1,cmp);
    for(int i = 1 ; i <= N ; ++i) L[i] = D[id[i]];
    for(int i = N ; i > 1 ; --i) {
        s[++tot] = id[i];
        int p = lower_bound(L + 1,L + i,L[i] + 2 * siz[s[tot]] - N) - L;
        if(L[p] != L[i] + 2 * siz[s[tot]] - N) {puts("-1");return;}
        t[tot] = id[p];
        siz[id[p]] += siz[id[i]];
    }
    for(int i = 1 ; i <= tot ; ++i) {add(s[i],t[i]);add(t[i],s[i]);}
    dfs(1,0);
    for(int i = 1 ; i <= N ; ++i) C[1] += dep[i];
    if(!dfs1(1,0)) {puts("-1");return;}
    for(int i = 1 ; i <= tot ; ++i) {
        out(s[i]);space;out(t[i]);enter;
    }
}
int main() {
#ifdef ivorysi
	freopen("f1.in","r",stdin);
#endif
    Solve();
	return 0;
}
