#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, d;

void solve()
{
	double ans;
	if(!d) ans = 1.0*(m-1)/n;
	else {
		ans = 2.0*(n-d)*(m-1)/n/n;
	}
	printf("%.8lf\n", ans);
}

int main()
{
	cin >> n >> m >> d;
	solve();
	return 0;
}