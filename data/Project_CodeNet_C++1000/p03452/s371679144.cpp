#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

#define INIT 2147483647

class e {
public:
	int v, w;
	e(int v, int w)
	:v(v),w(w)
	{}
};

vector<e> con[100001], rcon[100001];
int up[100001];
int n, m, el[200001][3];
int ind[100001], d[100001];

int fd(int u) {
	if(up[u]==0) return u;
	return up[u]=fd(up[u]);
}

void un(int u, int v) {
	int ru=fd(u), rv=fd(v);
	up[rv]=ru;
}

bool mark(int u) {
	for(int i=0;i<con[u].size();i++) {
		int v=con[u][i].v, w=con[u][i].w;
		if(d[v]==INIT) {
			d[v]=d[u]+w;
			if(!mark(v)) return false;
		}
		else if(d[v]!=d[u]+w) return false;
	}
	for(int i=0;i<rcon[u].size();i++) {
		int v=rcon[u][i].v, w=rcon[u][i].w;
		if(d[v]==INIT) {
			d[v]=d[u]-w;
			if(!mark(v)) return false;
		}
		else if(d[v]!=d[u]-w) return false;
	}
	return true;
}

int main() {
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++) {
		int u, v, w;
		scanf("%d %d %d",&u,&v,&w);
		el[i][0]=u; el[i][1]=v; el[i][2]=w;
		if(w==0) {
			if(fd(u)!=fd(v)) {
				un(u,v);
			}
		}
	}
	for(int i=0;i<m;i++) {
		int u=el[i][0], v=el[i][1], w=el[i][2];
		if(w==0) continue;
		if(fd(u)==fd(v)) {
			puts("No");
			return 0;
		}
		con[u].push_back(e(v,w));
		rcon[v].push_back(e(u,w));
		ind[v]++;
	}
	for(int i=1;i<=n;i++)
		d[i]=INIT;
	for(int i=1;i<=n;i++) if(ind[i]==0 && d[i]==INIT) {
		d[i]=0;
		if(!mark(i)) {
			puts("No");
			return 0;
		}
	}
	for(int i=1;i<=n;i++) {
		if(d[i]==INIT) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}