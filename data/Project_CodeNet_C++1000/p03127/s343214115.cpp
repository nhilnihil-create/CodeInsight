#include <cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
ll a[100005];
ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll ans = gcd(a[0], a[1]);
	for (int i = 2; i < n; i++) {
		ans = gcd(ans, a[i]);
	}
	cout << ans << endl;
	return 0;
}

