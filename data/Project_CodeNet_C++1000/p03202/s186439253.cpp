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

struct Node {
	int v, c;

	Node() {}
	Node(int v, int c):v(v), c(c) {}
};

int n;
int top;
int a[200010];
Node sta[200010];

inline void insert(int v, int x) {
	while(sta[top].v > v) --top;
	if(sta[top].v == v) sta[top].c++;
	else sta[++top] = Node(v, 1);
	if(top > 1 && sta[top].c == x) --top, insert(v - 1, x);
}

inline int chk(int x) {
	sta[top = 1] = Node(0, 0);
	for(int i = 2; i <= n; i++)
		if(a[i] <= a[i - 1]) insert(a[i], x);
	return sta[1].c == 0;
}

int main() {
#ifdef LOCAL
	FILE("");
#endif
	n = ri;
	for(int i = 1; i <= n; i++) a[i] = ri;

	int ct = 0;
	for(int i = 2; i <= n; i++) ct += a[i] > a[i - 1];
	if(ct == n - 1) return puts("1"), 0;
	int l = 2, r = n, res = 1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(chk(mid)) res = mid, r = mid - 1;
		else l = mid + 1;
	} printf("%d\n", res);
	return 0;
}