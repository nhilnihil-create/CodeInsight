#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
ll a[100010];
pair<ll,ll> x[100010];
int main() {
	int n,m;
	cin >> n >> m;
	rep(i,n) cin >> a[i];
	rep(i,m) {
		ll b,c; cin >> b >> c;
		x[i] = {c,b};
	}
	sort(x,x+m, greater<pair<ll,ll>>());
	sort(a,a+n);
	int id_a = 0, id_x = 0; //aのインデックス
	while (id_a < n && id_x < m)
	{
		int cnt = 0;
		while (true)
		{
			cnt++;
			if (id_a == n || a[id_a] > x[id_x].first) break;
			if (cnt > x[id_x].second) break;
			a[id_a] = x[id_x].first;
			id_a++;
 		}
		id_x++;
	}
	
	ll sum = 0;
	rep(i,n) sum += a[i];
	
	cout << sum << endl;
	
	return 0;
}