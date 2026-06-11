#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, B = y; i <= B; i ++)
#define ff(i, x, y) for(int i = x, B = y; i <  B; i ++)
#define fd(i, x, y) for(int i = x, B = y; i >= B; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 1e5 + 5;

int n;
ll d[N];
int a[N];

map<ll, int> bz;

int cmpa(int x, int y) {
	return d[x] > d[y];
}

int ans[N][2], ans0;
vector<int> e[N];

int siz[N];

void Noans() {
	pp("-1\n");
	exit(0);
}

ll sum;

void dg(int x, int y) {
	sum += y;
	ff(j, 0, e[x].size()) {
		dg(e[x][j], y + 1);
	}
}

int main() {
	scanf("%d", &n);
	fo(i, 1, n) scanf("%lld", &d[i]), bz[d[i]] = i, a[i] = i;
	sort(a + 1, a + n + 1, cmpa);
	fo(i, 1, n) siz[i] = 1;
	fo(i, 1, n - 1) {
		int x = a[i];
		if(siz[x] * 2 > n)
			Noans();
		ll y = d[x] - n + 2 * siz[x];
		if(!bz.count(y)) Noans();
		y = bz[y];
		siz[y] += siz[x];
		ans[++ ans0][0] = x, ans[ans0][1] = y;
		e[y].push_back(x);
	}
	dg(a[n], 0);
	if(sum != d[a[n]]) Noans();
	fo(i, 1, n - 1) pp("%d %d\n", ans[i][0], ans[i][1]);
}