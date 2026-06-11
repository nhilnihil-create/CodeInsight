#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
typedef long long lint;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
typedef unsigned long long ulint;
#define endl '\n'
#define fst first
#define sed second
#define pb push_back
#define mp make_pair
#define rint register int
#define newline putchar('\n')
#define leave_space putchar(' ')
#define all(x) (x).begin(), (x).end()
#define reveal(x) cerr << #x << " = " << (x) << endl
#define rep(it, f, e) for (rint it = (f); it <= (e); ++it)
#define per(it, f, e) for (rint it = (f); it >= (e); --it)
const int MAXN = 1e5 + 5;
queue<pii> que;
int dis[MAXN];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int k;
	cin >> k;
	memset(dis, 0x3f, sizeof(dis));
	rep (i, 1, 9) {
		que.push(mp(i % k, i));
		dis[i % k] = min(i, dis[i % k]);
	}
	while (!que.empty()) {
		pii u = que.front(); que.pop();
		if (!u.fst) continue;
		if (u.sed != dis[u.fst]) continue;
		rep (i, 0, 9) {
			int vi = (u.fst * 10 + i) % k;
			int vj = u.sed + i;
			if (dis[vi] > vj) {
				dis[vi] = vj;
				que.push(pii(vi, vj));
			}
		}
	}
	cout << dis[0] << endl;
	return 0;
}