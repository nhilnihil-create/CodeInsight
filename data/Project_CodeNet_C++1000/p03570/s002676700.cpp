#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define MAXN 200005
#define eps 1e-10
//#define ivorysi
using namespace std;
typedef long long int64;
typedef unsigned int u32;
typedef double db;
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
	if(x < 0) {x = -x;putchar('-');}
	if(x >= 10) {
		out(x / 10);
	}
	putchar('0' + x % 10);
}
char s[MAXN];
int sum[MAXN],N;
int dp[MAXN];
map<int,int> zz;
void Init() {
	scanf("%s",s + 1);
	N = strlen(s + 1);
	for(int i = 1 ; i <= N ; ++i) {
		sum[i] = sum[i - 1];
		sum[i] ^= (1 << s[i] - 'a');
	}
}
void Solve() {
	zz[0] = 0;
	for(int i = 1 ; i <= N ; ++i) {
		dp[i] = i;
		if(zz.count(sum[i])) dp[i] = min(dp[i],zz[sum[i]] + 1);
		for(int j = 0 ; j < 26 ; ++j) {
			if(zz.count(sum[i] ^ (1 << j))) dp[i] = min(dp[i],zz[sum[i] ^ (1 << j)] + 1);
		}
		if(!zz.count(sum[i])) zz[sum[i]] = dp[i];
		else zz[sum[i]] = min(zz[sum[i]],dp[i]);
	}
	out(dp[N]);enter;
}
int main() {
#ifdef ivorysi
	freopen("f1.in","r",stdin);
#endif
	Init();
	Solve();
}
