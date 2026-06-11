#define _USE_MATH_DEFINES
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<set>
#include<map>
#include<stdbool.h>
#include<math.h>
#include<sstream>
#include<math.h>
#include<vector>
#include<functional>
#include<queue>
#include<utility>
#include<bitset>
typedef long long ll;
#define N (1000000000+7)
#define INF 1e10
using namespace std;
typedef pair<ll, ll> P;


ll sumleft[200010];
ll sumright[200010];

bool isOK(ll* a,ll index, ll key) {
	if (a[index] >= key) return true;
	else return false;
}


ll binary_search(ll* a,ll key,ll l,ll r) {
	ll left = l - 1; //「index = 0」が条件を満たすこともあるので、初期値は -1
	ll right = (ll)r + 1; // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

	while (right - left > 1) {
		int mid = left + (right - left) / 2;

		if (isOK(a,mid, key)) right = mid;
		else left = mid;
	}

	return right;
}

int main(void) {
	ll n;
	cin >> n;
	vector<ll>a(n);
	for (ll i = 0;i < n;i++) cin >> a[i];
	for (ll i = 0;i < n;i++)sumleft[i + 1] = sumleft[i] + a[i];
	for (ll i = 0;i < n;i++)sumright[i + 1] = sumright[i] + a[n - 1 - i];
	ll ans = 10000000000000000;
	for (ll j = 2;j <= n - 2;j++) {
		ll ma = 0, mi = 10000000000000000;
		ll p = sumleft[j];
		ll i = binary_search(sumleft, p / 2, 1, j - 1);
		ll k = binary_search(sumright, (sumleft[n] - sumleft[j]) / 2, 1, n - j - 1);
		k = n - k + 1;
		for (ll x = i - 1;x <= i+1;x++) {
			for (ll y = k-1;y <= k+1;y++) {
				if ((1 <= x) && (x < j) && (j < y) && (y < n)) {
					ll ma = 0, mi = 10000000000000000;
					//cout << x << " " << j << " " << y << endl;
					//cout << sumleft[x] << " " << sumleft[j] - sumleft[x] << " "<<sumleft[y] - sumleft[j]<<" "<< sumleft[n] - sumleft[y] << endl;
					ma = max(ma, max(sumleft[x], sumleft[j] - sumleft[x]));
					ma = max(ma, max(sumleft[y] - sumleft[j], sumleft[n] - sumleft[y]));
					mi = min(mi, min(sumleft[x], sumleft[j] - sumleft[x]));
					mi = min(mi, min(sumleft[y] - sumleft[j], sumleft[n] - sumleft[y]));
					ans = min(ans, ma - mi);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}