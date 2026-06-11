#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define enter putchar('\n')
#define space putchar(' ')
#define MAXN 100005
#define eps 1e-8
//#define ivorysi
using namespace std;
typedef long long int64;
typedef double db;
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
char s[305];
int K,dp[305][305][305],N;
void update(int &x,int y) {
    x = max(x,y);
}
void Solve() {
    scanf("%s",s + 1);
    read(K);
    N = strlen(s + 1);
    for(int i = 1 ; i <= N ; ++i) 
	for(int j = 0 ; j <= K ; ++j)
	    dp[i][i][j] = 1;
    for(int d = 2 ; d <= N ; ++d) {
	for(int i = 1 ; i <= N ; ++i) {
	    int j = i + d - 1;
	    if(j > N) break;
	    for(int k = 0 ; k <= K ; ++k) {
		if(k) update(dp[i][j][k],dp[i][j][k - 1]);
		update(dp[i][j][k],dp[i + 1][j][k]);
		update(dp[i][j][k],dp[i][j - 1][k]);
		if(s[i] == s[j]) update(dp[i][j][k],dp[i + 1][j - 1][k] + 2);
		else if(k) update(dp[i][j][k],dp[i + 1][j - 1][k - 1] + 2);
	    }
	}
    }
    out(dp[1][N][K]);enter;
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    Solve();
    return 0;
}
