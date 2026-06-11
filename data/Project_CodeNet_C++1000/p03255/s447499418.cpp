#include <bits/stdc++.h>
#define MAX_N 200000
#define sum(l,r) (s[r]-s[l])
using namespace std;
typedef long long lnt;
template <class T> inline void read(T &x) {
	x = 0; int c = getchar(), f = 1;
	for (; !isdigit(c); c = getchar()) if (c == 45) f = -1;
	for (; isdigit(c); c = getchar()) (x *= 10) += f*(c-'0');
}
int n; lnt m, s[MAX_N+5];
int main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(s[i]), s[i] += s[i-1];
	lnt mi = s[n]*5+m*n*2, tot;
	for (int i = 1; i <= (n+1)/2; mi = min(mi, tot), i++) {
		tot = m*(n+i)+sum(max(0, n-2*i), n)*5; lnt c = 7;
		for (int j = n-2*i; tot < mi && j > 0; j -= i, c += 2)
			tot += sum(max(0, j-i), j)*c;
	}
	return printf("%lld\n", mi), 0;
}