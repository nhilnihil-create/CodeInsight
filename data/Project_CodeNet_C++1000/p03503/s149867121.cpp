#include <bits/stdc++.h>
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



int main() {
	fastIO;
	int n;
	cin >> n;
	vector<int> openMasks;
	for (int i = 0; i < n; i++) {
		int mask = 0;
		for (int j = 0; j < 10; j++) {
			int bit;
			cin >> bit;
			mask |= (bit << (10-j-1));
		}
		openMasks.push_back(mask);

	}

	int profits[n][11];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 11; j++) {
			cin >> profits[i][j];
		}
	}

	ll mx = -1e18;

	for (int i = 1; i < (1 << 10); i++) {
		ll p = 0;
		for (int j = 0; j < n; j++) {
			int mask = openMasks[j] & i;
			int idx = __builtin_popcount(mask);
			p += profits[j][idx];
		}
		mx = max(mx, p);
	}

	cout << mx;



}
