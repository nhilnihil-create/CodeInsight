#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define eps 1e-10
#define MAXN 10005
#define ba 47
//#define ivorysi
using namespace std;
typedef long long int64;
typedef unsigned int u32;
typedef double db;
template<class T>
void read(T &res) {
    res = 0;T f = 1;char c = getchar();
    while(c < '0' || c > '9') {
        if(c == '-') f = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9') {
        res = res * 10 +c - '0';
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
struct node {
    int to,next;
}E[MAXN * 2];
int sumE,head[MAXN],N;
int c[MAXN],ans;
int p[MAXN],tot;
void add(int u,int v) {
    E[++sumE].to = v;
    E[sumE].next = head[u];
    head[u] = sumE;
}
void dfs(int u,int fa) {
    p[u] = c[tot--];
    for(int i = head[u] ; i ; i = E[i].next) {
        int v = E[i].to;
        if(v != fa) {
            dfs(v,u);
        }
    }
}
void Solve() {
    read(N);
    int a,b;
    for(int i = 1 ; i < N ; ++i) {
        read(a);read(b);add(a,b);add(b,a);
    }
    for(int i = 1 ; i <= N ; ++i) read(c[i]);
    sort(c + 1,c + N + 1);
    for(int i = 1 ; i < N ; ++i) ans += c[i];
    tot = N;
    dfs(1,0);
    out(ans);enter;
    for(int i = 1 ; i <= N ; ++i) {
        out(p[i]);space;
    }
    enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}