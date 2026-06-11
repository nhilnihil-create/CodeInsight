#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 1005
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
#define dbg(x) cerr << #x << " = " << x << endl;
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define dbg3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;

vector<ll> a;
vector<ll> b;
int main()
{
	FASTIO
	/*
	//double start_time = clock();
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
//*/
	int T;
	//cin >> T;
	T = 1;
	for (int cs = 1; cs <= T; cs++) {
		ll n, m, q;
		cin >> n >> m >> q;
		for (int i = 0; i < n; i++) {
			ll x;
			cin >> x;
			a.push_back(x);
		}
		for (int i = 0; i < m; i++) {
			ll x;
			cin >> x;
			b.push_back(x);
		}

		//sort(a.begin(), a.end());
		//sort(b.begin(), b.end());
		a[n] = INT_MAX;
		b[m] = INT_MAX;
		while (q--) {
			ll x;
			cin >> x;
			ll l1 = upper_bound(a.begin(), a.end(), x) - a.begin();
			ll t = l1 - 1;
			t = max(0LL, t);
			l1 = min(n - 1, l1);
			///cerr << l1 << " " << a[l1] << " " << " "<<a[t]<<" "<< x << endl;
			ll tmp1 = abs(x - a[t]);// pichone
			ll tmp2 = abs(x - a[l1]); // samne
			///cerr << t << " " << tmp1 << " " << tmp2 << endl;
			///cerr << a[t] << " " << a[l1] << endl;
			ll r1 = upper_bound(b.begin(), b.end(), a[t]) - b.begin();
			ll r2 = upper_bound(b.begin(), b.end(), a[l1]) - b.begin();

			///cerr << r1 << " --> " << b[r1] << " && " << r2 << " --> " << b[r2] << endl;

			ll p =  min(abs(b[min(r1, m - 1)] - a[t]), abs(b[max(0LL, r1 - 1)] - a[t]));
			///cerr << b[r1] << " - " << a[t] << " && " << b[r1 - 1] << " - " << a[t] << endl;
			ll q = min(abs(b[min(r2, m - 1)] - a[l1]), abs(b[max(0LL, r2 - 1)] - a[l1]));
			///cerr << p << " " << q << endl;
			p += tmp1;
			q += tmp2;
			ll ans = min(p, q);
			//cout << ans << endl;
			//cerr << "------------------------\n";

			ll _l1 = upper_bound(b.begin(), b.end(), x) - b.begin();
			ll _t = _l1 - 1;
			_t = max(0LL, _t);
			_l1 = min(m - 1, _l1);
			//cerr << _l1 << " " << b[l1] << " " << " "<<b[t]<<" "<< x << endl;
			ll _tmp1 = abs(x - b[_t]);// pichone
			ll _tmp2 = abs(x - b[_l1]); // samne
			//cerr << _t << " " << _tmp1 << " " << _tmp2 << endl;
			//cerr << b[t] << " " << b[l1] << endl;
			ll _r1 = upper_bound(a.begin(), a.end(), b[_t]) - a.begin();
			ll _r2 = upper_bound(a.begin(), a.end(), b[_l1]) - a.begin();

			//cerr << _r1 << " --> " << a[r1] << " && " << _r2 << " --> " << a[r2] << endl;

			ll _p =  min(abs(a[min(_r1, n - 1)] - b[_t]), abs(a[max(0LL, _r1 - 1)] - b[_t]));
			//cerr << a[r1] << " - " << b[t] << " && " << a[r1 - 1] << " - " << b[t] << endl;
			ll _q = min(abs(a[min(_r2, n - 1)] - b[_l1]), abs(a[max(0LL, _r2 - 1)] - b[_l1]));
			//cerr << _p << " " << _q << endl;
			_p += _tmp1;
			_q += _tmp2;
			ll _ans = min(_p, _q);
			//cout << _ans << endl;
			cout << min(_ans, ans) << endl;
			//cerr << "---------777777777777777-------------\n";

		}
	}

	//double end_time = clock();
	//printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
	return 0;
}