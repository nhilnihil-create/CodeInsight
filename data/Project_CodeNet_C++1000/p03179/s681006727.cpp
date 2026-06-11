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
const int N = 3010, P = 1e9 + 7;
int n;
char st[N];
int f[N][N], pre[N][N], bak[N][N];
int main(){
	read(n);
	scanf("\n%s", st + 2);
	f[1][1] = pre[1][1] = bak[1][1] = 1;
	for (int i = 2; i <= n; i++){
		if (st[i] == '<')
			for (int j = 1; j <= i; j++) f[i][j] = pre[i - 1][j - 1];
			else for (int j = 1; j <= i; j++) f[i][j] = bak[i - 1][j];
		for (int j = 1; j <= i; j++)
			pre[i][j] = (pre[i][j - 1] + f[i][j]) % P;
		for (int j = i; j >= 1; j--)
			bak[i][j] = (bak[i][j + 1] + f[i][j]) % P;
	} 
	printf("%d\n", pre[n][n]);
	return 0;
}

