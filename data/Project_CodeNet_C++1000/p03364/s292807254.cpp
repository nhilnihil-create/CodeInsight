//Author:xht37
#include <bits/stdc++.h>

#define ui unsigned int
#define ll long long
#define ul unsigned ll
#define ld long double

#define pi pair <int, int>
#define fi first
#define se second
#define mp make_pair

#define ls (p << 1)
#define rs (ls | 1)
#define md ((t[p].l + t[p].r) >> 1)

#define vi vector <int>
#define pb push_back
#define pq priority_queue

#define dbg(x) cerr << #x" = " << x << endl
#define debug(...) fprintf(stderr, __VA_ARGS__)

#define fl(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)

using namespace std;

namespace io {
	const int SI = 1 << 21 | 1;
	char IB[SI], *IS, *IT, OB[SI], *OS = OB, *OT = OS + SI - 1, c, ch[100];
	int f, t;
	#define gc() (IS == IT ? (IT = (IS = IB) + fread(IB, 1, SI, stdin), IS == IT ? EOF : *IS++) : *IS++)
	inline void flush() {
		fwrite(OB, 1, OS - OB, stdout), OS = OB;
	}
	inline void pc(char x) {
		*OS++ = x;
		if (OS == OT) flush();
	}

	template <class I>
	inline void rd(I &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + (c & 15), c = gc());
		x *= f;
	}
	template <class I>
	inline void rd(I &x, I &y) {
		rd(x), rd(y);
	}
	template <class I>
	inline void rd(I &x, I &y, I &z) {
		rd(x), rd(y), rd(z);
	}
	template <class I>
	inline void rda(I *a, int n) {
		for (int i = 1; i <= n; i++) rd(a[i]);
	}
	inline void rdc(char &c) {
		for (c = gc(); c < 33 || c > 126; c = gc());
	}
	inline void rds(char *s, int &n) {
		for (c = gc(); c < 33 || c > 126; c = gc());
		for (n = 0; c >= 33 && c <= 126; s[++n] = c, c = gc());
		s[n+1] = '\0';
	}
	inline void rds(string &s) {
		for (c = gc(); c < 33 || c > 126; c = gc());
		for (s.clear(); c >= 33 && c <= 126; s.pb(c), c = gc());
	}

	template <class I>
	inline void print(I x, char k = '\n') {
		if (!x) pc('0');
		if (x < 0) pc('-'), x = -x;
		while (x) ch[++t] = x % 10 + '0', x /= 10;
		while (t) pc(ch[t--]);
		pc(k);
	}
	template <class I>
	inline void print(I x, I y) {
		print(x, ' '), print(y);
	}
	template <class I>
	inline void print(I x, I y, I z) {
		print(x, ' '), print(y, ' '), print(z);
	}
	template <class I>
	inline void printa(I *a, int n) {
		for (int i = 1; i <= n; i++) print(a[i], " \n"[i==n]);
	}
	inline void printc(char c) {
		pc(c);
	}
	inline void prints(char *s, int n) {
		for (int i = 1; i <= n; i++) pc(s[i]);
		pc('\n');
	}
	inline void prints(string s) {
		int n = s.length();
		while (t < n) pc(s[t++]);
		pc('\n'), t = 0;
	}
	struct Flush {
		~Flush() {
			flush();
		}
	} flusher;
}
using io::rd;
using io::rda;
using io::rdc;
using io::rds;
using io::print;
using io::printa;
using io::printc;
using io::prints;

const int N = 607;
int n, f[N][N], g[N][N], ans;
char s[N][N];

int main() {
	rd(n);
	for (int i = 1; i <= n; i++) rds(s[i], n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			s[i][j+n] = s[i+n][j] = s[i+n][j+n] = s[i][j];
	for (int i = 1; i <= n * 2; i++)
		for (int j = 1; j <= n * 2; j++) {
			int k = min(min(i, j), min(n * 2 + 1 - i, n * 2 + 1 - j));
			int &x = f[i][j] = 1;
			while (x < k && s[i+x][j-x] == s[i-x][j+x]) ++x;
		}
	for (int i = 1; i < n * 2; i++)
		for (int j = 1; j < n * 2; j++) {
			int k = min(min(i, j), min(n * 2 - i, n * 2 - j));
			int &x = g[i][j] = 0;
			while (x < k && s[i+x+1][j-x] == s[i-x][j+x+1]) ++x;
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			bool ok = 1;
			for (int k = 0; ok && k < n; k++)
				ok &= (k / 2 + 1 <= (k & 1 ? g[i+k/2][j+k/2] : f[i+k/2][j+k/2])),
				ok &= (k / 2 + 1 <= (k & 1 ? g[i+n-2-k/2][j+n-2-k/2] : f[i+n-1-k/2][j+n-1-k/2]));
			ans += ok;
		}
	print(ans);
	return 0;
}