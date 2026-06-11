#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define x_ real()
#define y_ imag()
#define cross(a, b) (conj(a)*(b)).imag()
#define dot(a, b) (conj(a)*(b)).real()
#define PI acos(-1)
#define F first
#define S second
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL)
#define fileIO freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef complex<ld> point;
typedef tuple<int, int, int> line;
typedef vector<point> polygon;
typedef pair<double, double> pd;
pair<int, int> dirs[] = { {1, 2}, {-1, 2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, -2}, {-1, -2} };
const double eps = 1e-6;
const int N = 1e5 + 7;




int main() {
	fastIO;
	ll n, m;
	cin >> n >> m;
	vector<ll> v(n+1);
	v[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		v[i] += v[i-1];
	}
	unordered_map<ll, vector<ll>> occ;
	for (int i = 0; i <= n; i++) {
		v[i] %= m;
		occ[v[i]].push_back(i);
	}

	ll ans = 0;
	for (int i = 0; i <= n; i++) {
		ll cnt = occ[v[i]].end() - upper_bound(occ[v[i]].begin(), occ[v[i]].end(), i);
		ans += cnt;
	}

	cout << ans;

}
