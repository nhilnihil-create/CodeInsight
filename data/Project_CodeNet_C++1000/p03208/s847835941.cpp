#include <iostream>
#include<string>
#include<cmath>
#include<ciso646>
#include<cstring>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;


int main()
{
	int k, n;
	cin >> n>>k;
	vector<ll> h(n);
	rep(i, n) cin >> h[i];
	ll ans = 3 + 1e9;;
	sort(h.begin(), h.end());
	rep(i, n-k+1) {
		ll cn = h[i + k-1] - h[i];
		ans = min(ans, cn);
	}
	cout << ans;
}