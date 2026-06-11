#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<tuple>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
int main() {
	int n, m; 
	cin >> n >> m;
	vector<ll> x(n), y(n), z(n);
	rep(i, n)cin >> x[i] >> y[i] >> z[i];
	int sign[2] = { 1,-1 };
	ll res = 0;
	rep(i, 2)rep(j, 2)rep(k, 2) {
		vector<ll> cakes(n);
		rep(c, n) {
			cakes[c] = x[c] * sign[i] + y[c] * sign[j] + z[c] * sign[k];
		}
		sort(cakes.begin(), cakes.end(), greater<ll>());
		ll tmp = 0;
		rep(c, m)tmp += cakes[c];
		res = max(res, tmp);
	}
	cout << res << endl;
	return 0;
}
