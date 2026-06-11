#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define space putchar('\n')
#define enter putchar(' ')
#define MAXN 100005
//#define ivorysi
using namespace std;
typedef long long int64;
template<class T>
void read(T &res) {
	res = 0;T f = 1;char c = getchar();
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
	if(x < 0){putchar('-');x = -x;}
	if(x >= 10) out(x / 10);
	putchar('0' + x % 10);
}
const int MOD = 998244353;
int N,ans;
pii S[MAXN];
int id[2][MAXN];
bool vis[MAXN];
bool cmp1(int a,int b) {
	return S[a].fi < S[b].fi;
}
bool cmp2(int a,int b) {
	return S[a].se < S[b].se;
}
int main() {
#ifdef ivorysi
	freopen("f1.in","r",stdin);
#endif
	read(N);
	for(int i = 1 ; i <= N ; ++i) {
		read(S[i].fi);read(S[i].se);
		id[0][i] = i;id[1][i] = i;
	}
	sort(id[0] + 1,id[0] + N + 1,cmp1);
	sort(id[1] + 1,id[1] + N + 1,cmp2);
	int64 ans = 0;
	memset(vis,0,sizeof(vis));
	int p[2];p[0] = N,p[1] = 1;
	int pos = 0;int64 tmp = 0;
	if(S[id[0][N]].fi > 0) {
		vis[id[0][p[0]]] = 1;--p[0];
	 	tmp += abs(S[id[0][N]].fi - pos);
		pos = S[id[0][N]].fi;
		int cur = 1;
		while(1) {
			if(cur == 1) {
				while(p[cur] <= N && vis[id[cur][p[cur]]]) ++p[cur];
				if(p[cur] > N) break;
				if(S[id[cur][p[cur]]].se >= pos) break;
				tmp += abs(S[id[cur][p[cur]]].se - pos);
				pos = S[id[cur][p[cur]]].se;
				vis[id[cur][p[cur]]] = 1;
			}
			else {
				while(p[cur] >= 1 && vis[id[cur][p[cur]]]) --p[cur];
				if(p[cur] < 1) break;
				if(S[id[cur][p[cur]]].fi <= pos) break;
				tmp += abs(S[id[cur][p[cur]]].fi - pos);
				pos = S[id[cur][p[cur]]].fi;
				vis[id[cur][p[cur]]] = 1;
			}
			cur ^= 1;
		}
		tmp += abs(pos);
	}
	ans = max(ans,tmp);
	memset(vis,0,sizeof(vis));
	pos = 0;tmp = 0;p[0] = N;p[1] = 1;
	if(S[id[1][1]].se < 0) {
		vis[id[1][1]] = 1;++p[1];
		tmp += abs(S[id[1][1]].se - pos);
		pos = S[id[1][1]].se;
		int cur = 0;
		while(1) {
			if(cur == 1) {
				while(p[cur] <= N && vis[id[cur][p[cur]]]) ++p[cur];
				if(p[cur] > N) break;
				if(S[id[cur][p[cur]]].se >= pos) break;
				tmp += abs(S[id[cur][p[cur]]].se - pos);
				pos = S[id[cur][p[cur]]].se;
				vis[id[cur][p[cur]]] = 1;
			}
			else {
				while(p[cur] >= 1 && vis[id[cur][p[cur]]]) --p[cur];
				if(p[cur] < 1) break;
				if(S[id[cur][p[cur]]].fi <= pos) break;
				tmp += abs(S[id[cur][p[cur]]].fi - pos);
				pos = S[id[cur][p[cur]]].fi;
				vis[id[cur][p[cur]]] = 1;
			}
			cur ^= 1;
		}
		tmp += abs(pos);
	}
	ans = max(ans,tmp);
	out(ans);enter;
}
