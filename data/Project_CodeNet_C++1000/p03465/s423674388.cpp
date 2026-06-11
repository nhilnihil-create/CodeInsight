#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 2005, MI = 1e6;
int read() {
	static streambuf* in = cin.rdbuf();
	#define gc (p1 == p2 && (p2 = (p1 = buf) + in -> sgetn(buf, MI), p1 == p2) ? -1 : *p1++)
	static char buf[MI], *p1, *p2;
	int c = gc, r = 0;
	while(c < 48) c = gc;
	while(c > 47) r = (r << 3) + (r << 1) + (c & 15), c = gc;
	return r;
}
int n, a[N], sum;
bitset <N*N> bst;
int main() {
	#ifdef local
		freopen("in.txt", "r", stdin);
	#endif
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	n = read();
	bst[0] = 1;
	rep(i, 1, n) sum += a[i] = read(), bst |= bst << a[i];
	sum = (sum + 1) / 2;
	while(!bst[sum]) sum++;
	return !(cout << sum);
}