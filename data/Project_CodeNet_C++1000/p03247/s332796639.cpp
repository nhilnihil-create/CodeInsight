#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define enter putchar('\n')
#define space putchar(' ')
//#define ivorysi
#define MAXN 100005
typedef long long int64;
using namespace std;
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
int N;
int M = 0;
int64 op[35],sum,X[1005],Y[1005];
int64 dx[] = {1,0,-1,0},dy[] = {0,-1,0,1};
char s[1005][45];
const char *dir = "RDLU";
void Solve() {
	read(N);
	for(int i = 1 ; i <= N ; ++i) {
		read(X[i]);read(Y[i]);
	}
	for(int i = 2 ; i <= N ; ++i) {
		if((abs(X[i]) + abs(Y[i])) % 2 != (abs(X[1]) + abs(Y[1])) % 2)  {
			puts("-1");return ;
		}
	}
	bool flag = 0;
	flag = ((abs(X[1]) + abs(Y[1])) % 2 == 0);
	if(flag) {op[++M] = 1;}
	for(int i = 30 ; i >= 0 ; --i) {op[++M] = 1 << i;sum += op[M];}
	pii st = mp(0,0);
	if(flag) st = mp(1,0);
	for(int i = 1 ; i <= N ; ++i) {
		if(flag) s[i][1] = 'R';
		pii p = st;
		int64 tmp = sum;
		for(int j = flag ? 2 : 1 ; j <= M ; ++j) {
			for(int k = 0 ; k <= 3 ; ++k) {
				int64 tx = p.fi + dx[k] * op[j],ty = p.se + dy[k] * op[j];
				int64 a = abs(tx - X[i]) + abs(ty - Y[i]);
				if(a <= tmp - op[j]) {
					tmp -= op[j];
					s[i][j] = dir[k];
					p = mp(tx,ty);
					break;
				}
			}
		}
	}
	out(M);enter;
	for(int i = 1 ; i <= M ; ++i) {
		out(op[i]);space;
	}
	enter;
	for(int i = 1 ; i <= N ; ++i) {
		for(int j = 1 ; j <= M ; ++j) {
			putchar(s[i][j]);
		}
		enter;
	}
}
int main() {
#ifdef ivorysi
	freopen("f1.in","r",stdin);
#endif
	Solve();
}
