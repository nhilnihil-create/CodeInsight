// luogu-judger-enable-o2
#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++i)
#define dep(i, j, k) for(int i = j; i >= k; --i)
#define SIZE(x) (int)(x.size())
#define to(x) (x > n ? x - n : x)

typedef long long ll;

using namespace std;

const int maxn = 2e5 + 5;

int n, a[maxn], b[maxn], L, R, vis[maxn];
set<int> Q[maxn], S, now;
ll ans = 0, rnt = 0;

inline int read() {
	char ch = getchar(); int u = 0, f = 1;
	while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
	while(isdigit(ch))  { u = u * 10 + ch - 48; ch = getchar(); } return u * f;
}

int main() {
	n = read();
	rep(i, 1, n) S.insert(i);
	rep(i, 2, 2 * n) if(i * (i - 1) == 2 * n) {
		puts("Yes");
		printf("%d\n", i);
		rep(j, 1, i) {
			int P = j;
			if(Q[j].size() < i - 1) {
				for(int v : S) if(!Q[j].count(v)) {
					Q[j].insert(v);
					rep(k, P + 1, i) 
						if(Q[k].size() < i - 1 && !Q[k].count(v)) { 
							Q[k].insert(v); P = k; break;
						}
					S.erase(v);
					if(Q[j].size() >= i - 1) break;
				}
			}
			printf("%d ", i - 1);
			for(int v : Q[j]) printf("%d ", v);
			putchar('\n');
		} return 0;
	} puts("No");
	return 0;
}