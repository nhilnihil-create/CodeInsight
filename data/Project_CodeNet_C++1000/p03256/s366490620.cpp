#include<cstdio>
#include<queue>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
const int MAXN = 200005;
const int MAXM = 2000005;
struct edge{
    int to;
    edge *nxt;
}edges[MAXM], *adj[4*MAXN], *ecnt = &edges[0];
char s[MAXN];
void addedge(int u, int v) {
    edge *p = (++ecnt);
    p->to = v, p->nxt = adj[u], adj[u] = p;
}
int indeg[4*MAXN + 5];
int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    scanf("%s", s+1);
    for(int i=1;i<=M;i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if( a == b ) {
            addedge(a+N, a+2*N);
            addedge(a+3*N, a);
        }
        else {
            if( s[a] == s[b] ) {
                addedge(a+N, b);
                addedge(b+N, a);
                addedge(a+3*N, b);
                addedge(b+N, a+2*N);
                addedge(b+3*N, a);
                addedge(a+N, b+2*N);
                addedge(a+3*N, b+2*N);
                addedge(b+3*N, a+2*N);
            }
            else {
                addedge(a, b+N);
                addedge(b, a+N);
                addedge(a+2*N, b+N);
                addedge(b, a+3*N);
                addedge(b+2*N, a+N);
                addedge(a+2*N, b+N);
                addedge(a+2*N, b+3*N);
                addedge(b+2*N, a+3*N);
            }
        }
    }
    for(int i=1;i<=4*N;i++) {
        for(edge *p=adj[i];p!=NULL;p=p->nxt)
            indeg[p->to]++;
    }
    queue<int>que;
    for(int i=1;i<=4*N;i++)
        if( !indeg[i] ) que.push(i);
    int cnt = 0;
    while( !que.empty() ) {
        cnt++;
        int f = que.front(); que.pop();
        for(edge *p=adj[f];p!=NULL;p=p->nxt) {
            indeg[p->to]--;
            if( !indeg[p->to] ) que.push(p->to);
        }
    }
    if( cnt == 4*N ) puts("No");
    else puts("Yes");
}