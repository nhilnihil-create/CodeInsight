#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++ it)

inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

int n;
int a[200005];

bool check(int mxc) {
	set <pii> nw;
	rep(i, n) if (i) {
		if (a[i] > a[i - 1]) continue;
		while (!nw.empty() && nw.rbegin() -> first > a[i]) nw.erase(-- nw.end());
		int nwpos = a[i];
		while (nwpos && !nw.empty() && nw.rbegin() -> first == nwpos && nw.rbegin() -> second == mxc) {
			nw.erase(-- nw.end()); -- nwpos;
		}
		if (!nwpos) return 0;
		if (!nw.empty() && nw.rbegin() -> first == nwpos) {
			int x = nw.rbegin() -> second;
			nw.erase(-- nw.end()); nw.insert(mp(nwpos, x + 1));
		} else {
			if (2 > mxc) return 0;
			nw.insert(mp(nwpos, 2));
		}
	}
	return 1;
}

int main() {
	n = read();
	rep(i, n) a[i] = read();
	int lb = 1, rb = n;
	while (lb < rb) {
		int md = (lb + rb) >> 1;
		if (check(md)) rb = md;
		else lb = md + 1;
	}
	printf("%d\n", lb);
	return 0;
}