#include<iostream>
#include<cstdio>
#include<cstring>
#include <fstream>
#include<string>
#include<sstream>
#include<algorithm>
#include<bitset>
#include<vector>
#include<deque>
#include<queue>
#include<list>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<iomanip>
#include <functional>
#include <math.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const long long int MOD = 1000000007;
const int INF = 1000000007;
const double EPS = 1e-10;
const double PI = 3.14159265359;
const int N = 200005;
//cout << fixed << std::setprecision(9)
//--------------------------

int n;
ll a[N], h[N], dp[N];
P flowers[N];

ll BIT[N];
void set_val(ll *bit, int ind, ll val)
{
	ind++;
	while (ind < N) {
		bit[ind] = max(bit[ind], val);
		ind += ind & -ind;
	}
}
ll max_val(ll *bit, int ind)
{
	ll res = 0;
	ind++;
	while (ind) {
		res = max(res, bit[ind]);
		ind -= ind & -ind;
	}
	return res;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		flowers[i].first = h[i];
		flowers[i].second = i;
	}
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(flowers, flowers + n);

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int ind = flowers[i].second;
		dp[ind] = max_val(BIT, ind - 1) + a[ind];
		set_val(BIT, ind, dp[ind]);
		ans = max(ans, dp[ind]);
	}
	cout << ans << endl;

	return 0;
}

