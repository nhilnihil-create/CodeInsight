#include <bits/stdc++.h>
#define rep(i, n) for (rint i = 1; i <= (n); i ++)
#define re0(i, n) for (rint i = 0; i < (int) n; i ++)
#define travel(i, u) for (rint i = head[u]; i; i = e[i].nxt)
#define rint int
using namespace std;
     
typedef long long lo;
     
template<typename tp> inline void read(tp &x) {
	x = 0; char c = getchar(); int f = 0;
	for (; c < '0' || c > '9'; f |= c == '-', c = getchar());
	for (; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar());
	if (f) x = -x;
}

#define GG (puts("NO"), exit(0))
const int N = 3e5 + 233;
int H, W, n, sr, sc;
char S[N], T[N];

int main(void) {
	read(H); read(W); read(n);
	read(sr); read(sc);
	scanf("%s", S + 1);
	scanf("%s", T + 1);
	{
		int l = 0, r = H + 1;
		int die = 0;
		for (int i = n; i >= 1; i--) {
			
			if (T[i] == 'U') r++;
			if (T[i] == 'D') l--;
			l = max(l, 0);
			r = min(r, H + 1);
			if (l + 1 >= r) die = 1;
			
			if (S[i] == 'U') l++;
			if (S[i] == 'D') r--;
			if (l + 1 >= r) die = 1;
			l = max(l, 0);
			r = min(r, H + 1);
		}
		cerr << l << " " << r << " " << die << "\n";
		if (die || sr <= l || sr >= r) GG;
	}
	{
		int l = 0, r = W + 1;
		int die = 0;
		for (int i = n; i >= 1; i--) {
			
			if (T[i] == 'L') r++;
			if (T[i] == 'R') l--;
			l = max(l, 0);
			r = min(r, W + 1);
			if (l + 1 >= r) die = 1;
			
			if (S[i] == 'L') l++;
			if (S[i] == 'R') r--;
			if (l + 1 >= r) die = 1;
			l = max(l, 0);
			r = min(r, W + 1);
		}
		cerr << l << " " << r << " " << die << "\n";
		if (die || sc <= l || sc >= r) GG;
	}
	cout << "YES\n";
}
