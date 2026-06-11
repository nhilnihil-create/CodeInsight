#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define pdi pair<db,int>
#define mp make_pair
#define pb push_back
#define enter putchar('\n')
#define space putchar(' ')
#define eps 1e-8
#define mo 974711
#define MAXN 100005
//#define ivorysi
using namespace std;
typedef long long int64;
typedef double db;
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
int N,M;
int fa[MAXN],dis[MAXN];
int getfa(int u) {
    if(u == fa[u]) return u;
    else {
	int t = getfa(fa[u]);
	dis[u] += dis[fa[u]];
	return fa[u] = t;
    }
}
void Solve() {
    read(N);read(M);
    for(int i = 1 ; i <= N ; ++i) {
	fa[i] = i;dis[i] = 0;
    }
    int l,r,d;
    for(int i = 1 ; i <= M ; ++i) {
	read(l);read(r);read(d);
	if(getfa(l) == getfa(r)) {
	    if(dis[r] - dis[l] != d) {
		puts("No");
		return;
	    }
	}
	else {
	    int p = getfa(r),q = getfa(l);
	    fa[p] = q;
	    dis[p] = dis[l] - dis[r] + d;
	}
    }
    puts("Yes");
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}
