/********************************************************************************
	
	Code by a weak man who named CYJian, and he hopes the code can get more points.

	Algorithm: 

 ********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//{{{ FAST IO AND SOME FUNCTIONS
const int __SIZE = 1 << 18;
char ibuf[__SIZE], *iS, *iT;

#define ge (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++)
#define ri read_int()
#define rl read_ll()
#define ra read_alpha()
#define FILE(s) freopen(s"in", "r", stdin), freopen(s"out", "w", stdout)

template<typename T>
inline void read(T &x) {
	char ch, t = 0; x = 0;
	while(!isdigit(ch = ge)) t |= ch == '-';
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch = ge;
	x = t ? -x : x;
}
inline char read_alpha() { char c = ge; while(!isalpha(c) && c != EOF) c = ge; return c; }
inline int read_int() { int x; return read(x), x; }
inline ll read_ll() { ll x; return read(x), x; }

template<typename T> inline void chkmin(T&a, T b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T&a, T b) { a = a > b ? a : b; }
//}}}

int x[1010];
int y[1010];
int len[33];

int main() {
#ifdef LOCAL
	FILE("");
#endif
	int n = ri;
	for(int i = 1; i <= n; i++)
		x[i] = ri, y[i] = ri;
	int tmp = abs(x[1] + y[1]) & 1;
	for(int i = 1; i <= n; i++)
		if((abs(x[i] + y[i]) & 1) != tmp)
			return puts("-1"), 0;
	printf("%d\n1", 32 - tmp);
	len[1] = 1; int N = 1;
	if(tmp) {
		for(int i = 1; i <= 30; i++) printf(" %d", len[++N] = 1 << i);
		puts("");
	} else {
		for(int i = 0; i <= 30; i++) printf(" %d", len[++N] = 1 << i);
		puts("");
	}
	char s[40];
	memset(s, 0, sizeof(s));
	for(int i = 1; i <= n; i++) {
		ll nx = 0, ny = 0;
		for(int j = N; j; --j) {
			ll dx = x[i] - nx, dy = y[i] - ny;
			if(abs(dx) > abs(dy)) {
				if(dx > 0) nx += len[j], s[j] = 'R';
				else nx -= len[j], s[j] = 'L';
			} else {
				if(dy > 0) ny += len[j], s[j] = 'U';
				else ny -= len[j], s[j] = 'D';
			}
		} printf("%s\n", s + 1);
	}
	return 0;
}