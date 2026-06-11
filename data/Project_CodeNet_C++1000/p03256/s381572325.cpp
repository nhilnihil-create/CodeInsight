#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+ 10;
const int M = 4e5 + 10;//undirect edge

struct Edge{
	int to, next, val;
}e[M];

char col[N];
int aflag[N], bflag[N], q[N], del[N], ecnt, head[N];

inline void adde(int x, int y) {
	e[++ecnt].to = y;
	e[ecnt].next = head[x];
	head[x] = ecnt;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	scanf("%s", col + 1);
	for(int i = 1, la, lb; i <= m; ++i) {
		scanf("%d %d", &la, &lb);
		adde(la, lb);
		adde(lb, la);
		if(col[lb] == 'A') aflag[la] += 1;
		else bflag[la] += 1;
		if(col[la] == 'A') aflag[lb] += 1;
		else bflag[lb] += 1;
	}	
	int qhd = 1, qtl = 1;
	for(int i = 1; i <= n; ++i){
		if(!aflag[i] || !bflag[i])
			q[qtl++] = i;
	}
	while(qhd != qtl){
		int u = q[qhd++], qwq;
		if(del[u]) continue;
		del[u] = 1;
		if(col[u] == 'A') qwq = 1;
		else qwq = 2;
		for(int i = head[u]; i; i = e[i].next){
			if(!del[e[i].to]){
				if(qwq == 1) {
					aflag[e[i].to]--;
					if(!aflag[e[i].to])
						q[qtl++] = e[i].to;
				}else {
					bflag[e[i].to]--;
					if(!bflag[e[i].to])
						q[qtl++] = e[i].to;
				}				
			}

		}
		
	}
	for(int i = 1; i <= n; ++i)
		if(!del[i]){
			printf("Yes");
			return 0;
		}
	printf("No");
	return 0;	
}
