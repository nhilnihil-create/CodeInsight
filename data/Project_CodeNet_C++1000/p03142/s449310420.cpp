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

int N, M, fa[100005], deg[100005], deg0[100005], topd, tope;
struct Edge {int np; Edge *nxt;} E[100005], *V[100005];

inline void addedge(const int &u, const int &v){
	E[++tope].np = v, E[tope].nxt = V[u], V[u] = E + tope;
}

int main(){
	getint(N), getint(M);
	for(register int i = 1; i < N + M; i++){
		int u, v; getint(u), getint(v);
		addedge(u, v), deg[v]++;
	}
	for(register int i = 1; i <= N; i++) if(!deg[i]) deg0[++topd] = i;
	for(register int i = 1; i <= N; i++){
		const int u = deg0[topd--];
		for(register Edge *ne = V[u]; ne; ne = ne->nxt)
			if(fa[ne->np] = u, --deg[ne->np] == 0) deg0[++topd] = ne->np;
	}
	for(register int i = 1; i <= N; i++) printf("%d\n", fa[i]);
	return 0;
}