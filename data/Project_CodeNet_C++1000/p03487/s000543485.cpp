#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
ll a[100005];
int main() {
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	ll count = 1;
	ll ans = 0;
	for (int i = 0; i < n-1; i++) {
		if (a[i] == a[i + 1]) {
			count++;
		}
		else {
			if (a[i] - count <= 0) {
				ans += min(abs(a[i] - count), count);
			}
			else {
				ans += count;
			}
			count = 1;
		}
	}
	if (a[n-1] - count <= 0) {
		ans += min(abs(a[n-1] - count), count);
	}
	else {
		ans += count;
	}
	cout << ans << endl;
	return 0;
}


