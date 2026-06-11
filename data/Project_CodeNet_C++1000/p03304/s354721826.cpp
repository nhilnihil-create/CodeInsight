#include <bits/stdc++.h>
using namespace std;
using lint = long long;

signed main(){
	double n, m, d, ans; cin >> n >> m >> d;
	if(d == 0) ans = (m - 1.0) / n;
	else ans = 2.0 * (n - d) * (m - 1) / (n * n);
	cout << setprecision(10) <<  ans << endl;
}