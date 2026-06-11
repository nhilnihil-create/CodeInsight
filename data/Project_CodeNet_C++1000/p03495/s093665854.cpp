#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int a[200005];
int check[200005] = {};
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		check[a[i]]++;
	}
	ll sum = 0;
	for (int i = 0; i <= 200005; i++) {
		if (check[i] > 0) {
			sum++;
		}
	}
	if (k >= sum) {
		cout << "0" << endl;
		return 0;
	}
	sort(check, check + 200005);
	ll ans = 0;
	ll count = 0;
	for (int i = 0; i <= 200005; i++) {
		if (check[i] > 0) {
			count++;
		    ans += check[i];
		}
		if (count == sum - k) {
			break;
		}
	}
	cout << ans << endl;
	return 0;
}