#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

int main()
{
	ll d, n, m;
	cin >> n >> m >> d;
	double ans = 1.0;
	if (d == 0) {
		ans /= n;
		ans *= m - 1;
		printf("%.7f\n", ans);
	}
	else {
		ans *= 2 * (n - d);
		ans /= n * n;
		ans *= (m - 1);
		printf("%.7f\n", ans);
	}
}
