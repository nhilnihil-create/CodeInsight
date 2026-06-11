#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
const int MX = 200005;
int n, m, c[MX][2], a, b, qu[MX], t, k = 1, out[MX];
char s[MX];
vector<int> G[MX];
int main(){
	scanf("%d%d\n%s", &n, &m, s);
	rep(i,m){
		scanf("%d%d", &a, &b);
		G[--a].push_back(--b);
		G[b].push_back(a);
		c[a][s[b]-'A']++;
		c[b][s[a]-'A']++;
	}
	a = b = 0;
	rep(i,n) if(!out[i] && !(c[i][0] && c[i][1])){
		out[qu[b++]=i] = 1;
		while(a < b){
			t = qu[a++];
			for(int u: G[t]) if(!out[u] && !--c[u][s[t]-'A']){
				out[qu[b++]=u] = 1;
			}
		}
	}
	rep(i,n) k &= out[i];
	puts(k ? "No" : "Yes");
}