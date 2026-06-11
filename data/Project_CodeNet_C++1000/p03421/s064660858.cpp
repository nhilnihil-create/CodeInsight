#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
//#define ivorysi
#define mp make_pair
#define pb push_back
#define enter putchar('\n')
#define space putchar(' ')
#define MAXN 300005
using namespace std;
typedef long long int64;
typedef double db;
typedef unsigned int u32;
template<class T>

void read(T &res) {
	res = 0;T f = 1;char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9' ) {
		res = res * 10 - '0' + c;
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

int N,A,B;
int cnt[MAXN];

void Solve() {
	read(N);read(A);read(B);
	int d = (N - 1) / A + 1,u = N - A + 1;
	if(B > u || B < d) {puts("-1");return;}
	cnt[1] = A;
	int t = N - A;
	for(int i = 2 ; i <= B ; ++i) {
		cnt[i] = t - A >= B - i ? A : t - (B - i);
		t -= cnt[i];
	}
	t = N;
	for(int i = B ; i >= 1 ; --i) {
		for(int j = t - cnt[i] + 1 ; j <= t ; ++j) {
			out(j);space;
		}
		t -= cnt[i];
	}
	enter;
}

int main() {
	Solve();
	return 0;
}