#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ph push
#define ptc putchar
#define enter putchar('\n')
#define mod 998244353
using namespace std;
typedef pair<int,int> pii;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef long long lnt;
inline int read(){
	int x = 0;char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) x = (x << 1) + (x << 3) + c - '0' , c = getchar();
	return x;
}
inline void write(int x){
	if (!x){
       ptc('0');
       return;
	}
	int dg[20] , len = 0;
	while (x) dg[len++] = x % 10 , x /= 10;
	while (len--) ptc(dg[len]+'0');
}
inline void writeln(int x){
	write(x);
	ptc('\n');
}
inline int add(int x,int y){
	x += y;if (x >= mod) x -= mod;
	return x;
}
inline int sub(int x,int y){
	x -= y;if (x < 0) x += mod;
	return x;
}
inline int qpow(int x,int y){
	int res = 1;
	while (y){
		if (y & 1) res = 1ll * res * x % mod;
		x = 1ll * x * x % mod;y >>= 1;
	}
	return res;
}

const int N = 2e5 + 10;

vector <int> G[N];
set<pii> s;
int n , m , col[N] , d[N][2] , typ[N] , died[N];
char t[N];
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",t + 1);
	for (int i = 1;i <= n;i++){
		col[i] = t[i] - 'A';
	}
	for (int i = 1;i <= m;i++){
		int u , v;scanf("%d%d",&u,&v);
		G[u].pb(v);G[v].pb(u);
		d[u][col[v]]++;
		d[v][col[u]]++;
	}
	
	for (int i = 1;i <= n;i++){
		typ[i] = (d[i][0] ? 1 : 0) + (d[i][1] ? 2 : 0);
		s.insert(mp(typ[i] , i));
	}
	
	while (s.size() && (*s.begin()).first != 3){
		pii cur = *s.begin();s.erase(s.begin());
		died[cur.second] = 1;
		
		for (int u : G[cur.second]){
			if (!died[u]){
				d[u][col[cur.second]]--;
				if (!d[u][col[cur.second]]){
					s.erase(s.find(mp(typ[u] , u)));
					typ[u] -= 1 << col[cur.second];
				
					s.insert(mp(typ[u] , u));
				}
				
			}
		}
	}
	for (int i = 1;i <= n;i++) if (!died[i]) return puts("Yes") , 0;
	puts("No");
	return 0;
}
