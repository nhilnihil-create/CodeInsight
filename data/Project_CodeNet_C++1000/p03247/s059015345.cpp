# include <bits/stdc++.h>
using namespace std;
namespace Base{
	# define mr make_pair
	typedef long long ll;
	typedef double db;
	const int inf = 0x3f3f3f3f, INF = 0x7fffffff;
	const ll  infll = 0x3f3f3f3f3f3f3f3fll, INFll = 0x7fffffffffffffffll;
	template<typename T> void read(T &x){
    	x = 0; int fh = 1; double num = 1.0; char ch = getchar();
		while (!isdigit(ch)){ if (ch == '-') fh = -1; ch = getchar(); }
		while (isdigit(ch)){ x = x * 10 + ch - '0'; ch = getchar(); }
	    if (ch == '.'){
	    	ch = getchar();
	    	while (isdigit(ch)){num /= 10; x = x + num * (ch - '0'); ch = getchar();}
		}
		x = x * fh;
	}
	template<typename T> void chmax(T &x, T y){x = x < y ? y : x;}
	template<typename T> void chmin(T &x, T y){x = x > y ? y : x;}
}
using namespace Base;

struct point{
	int x, y;
}p[4010];
int n, flag[2], tmp;
ll g[110];
int main(){
	read(n);
	for (int i = 1; i <= n; i++){
		read(p[i].x); read(p[i].y);
		flag[((p[i].x + p[i].y) % 2 + 2) % 2] = true;
	}
	if (flag[0] + flag[1] > 1){
		printf("-1\n");
		return 0;
	}
	if (flag[0] == 1) tmp = 40; else tmp = 39;
	printf("%d\n", tmp);
	g[1] = 1;
	for (int i = 2; i <= tmp; i++) g[i] = g[i - 1] * 2;
	g[40] = 1;
	for (int i = 1; i <= 39 / 2; i++) swap(g[i], g[39 - i + 1]);
	for (int i = 1; i <= tmp; i++)
		printf("%lld%c", g[i], (i == tmp) ? '\n' : ' ');
	for (int i = 1; i <= n; i++){
		ll nowx = 0, nowy = 0;
		for (int j = 1; j <= tmp; j++){
			ll dx = nowx - p[i].x, dy = nowy - p[i].y;
			if (abs(dx) >= abs(dy)){
				if (nowx < p[i].x) {printf("R"); nowx += g[j];}
					else {printf("L"); nowx -= g[j];}
			}
			else {
				if (nowy < p[i].y) {printf("U"); nowy += g[j];}
					else {printf("D"); nowy -= g[j];}
			}
		}
		printf("\n");
	}
	return 0;
}