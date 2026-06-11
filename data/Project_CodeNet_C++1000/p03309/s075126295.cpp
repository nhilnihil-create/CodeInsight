#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	

	vector<ll> a(n);
	
	
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i] =a[i]- i - 1;
	}
	sort(a.begin(), a.end());
	vector<ll> cs(n);
  cs[0]=a[0];
	for(int i=1;i<n;i++){
      cs[i]=cs[i-1]+a[i];
    }

	ll ans = 1e18;
	for (int i = 0; i < n; ++i) {
		ll res = 0;
		res += a[i] * (i + 1) - cs[i];
		res += (cs.back() - cs[i]) - a[i] * (n - i - 1);
		ans = min(ans, res);
	}
	cout << ans << endl;
	return 0;
}
