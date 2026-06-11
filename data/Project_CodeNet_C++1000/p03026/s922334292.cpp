#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

template <typename Tp> inline void getint(Tp &num){
	register int ch, neg = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') neg = 1;
	num = ch & 15;
	while(isdigit(ch = getchar())) num = num * 10 + (ch & 15);
	if(neg) num = -num;
}

int N, c[10005], M, d[10005], deg[10005], stk[10005], tops = 0, tope = 0;
struct Edge {int np; Edge *nxt;} E[20005], *V[10005];

inline void addedge(const int &u, const int &v){
	E[++tope].np = v, E[tope].nxt = V[u], V[u] = E + tope;
}

int main(){
	getint(N);
	for(register int i = 1; i < N; i++){
		int u, v; getint(u), getint(v);
		addedge(u, v), addedge(v, u), deg[u]++, deg[v]++;
	}
	for(register int i = 1; i <= N; i++) getint(c[i]);
	sort(c + 1, c + N + 1);
	for(register int i = 1; i <= N; i++) if(deg[i] == 1) stk[++tops] = i;
	for(register int i = 1; i <= N; i++){
		const int u = stk[tops--]; M += d[u] = c[i];
		for(register Edge *ne = V[u]; ne; ne = ne->nxt) if(!d[ne->np] && --deg[ne->np] == 1) stk[++tops] = ne->np;
	}
	printf("%d\n", M - c[N]);
	for(register int i = 1; i <= N; i++) printf("%d ", d[i]);
	return 0;
}