#include <iostream>
#include <cstdio>
#define fi first
#define se second
#define mp make_pair
using namespace std;
pair <int, int> a[100005];
int d[100];
int aabs(int x){
	return x >= 0 ? x : -x;
}
long long dis(pair <int, int> x, pair <int, int> y){
	return 1LL * aabs(x.fi - y.fi) + aabs(x.se - y.se);
}
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i].fi >> a[i].se;
	int flag = (a[1].fi ^ a[1].se) & 1;
	for (int i = 2; i <= n; ++ i)
		if (((a[i].fi ^ a[i].se) & 1) != flag){
			cout << -1 << endl;
			return 0;
		}
	int m = 31;
	for (int i = 1; i <= m; ++ i)
		d[i] = 1 << (m - i);
	if (flag == 0)
		d[++ m] = 1;
	cout << m << endl;
	for (int i = 1; i <= m; ++ i)
		cout << d[i] << " ";
	cout << endl;
	for (int i = 1; i <= n; ++ i){
		pair <int, int> p(0, 0);
		for (int j = 1; j <= m; ++ j){
			pair < pair <long long, char> , pair <int, int> > pl, pr, pu, pd, mx;
			pl.se = mp(p.fi - d[j], p.se);
			pl.fi = mp(dis(a[i], pl.se), 'L');
			pr.se = mp(p.fi + d[j], p.se);
			pr.fi = mp(dis(a[i], pr.se), 'R');
			pu.se = mp(p.fi, p.se + d[j]);
			pu.fi = mp(dis(a[i], pu.se), 'U');
			pd.se = mp(p.fi, p.se - d[j]);
			pd.fi = mp(dis(a[i], pd.se), 'D');
			mx = min(min(pl, pr), min(pu, pd));
			p = mx.se;
			putchar(mx.fi.se);
		}
		cout << endl;
	}
}
