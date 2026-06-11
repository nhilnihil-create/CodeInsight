#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define space putchar(' ')
#define enter putchar('\n')
#define MAXN 80005
#define eps 1e-10
//#define ivorysi
using namespace std;
typedef long long int64;
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
string s;
string tar = "keyence";
void Solve() {
	cin >> s;
	int p = 0;
	while(s[p] == tar[p]) ++p;
	int q = 0;
	while(s[s.length() - 1 - q] == tar[tar.length() - 1 - q]) ++q;
	if(p + q >= tar.length()) puts("YES");
	else puts("NO");
}
int main() {
	Solve();
}