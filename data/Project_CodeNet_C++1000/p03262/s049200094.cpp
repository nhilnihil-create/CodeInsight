#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
ll point[100005];
ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}
int main() {
	int n;
	ll x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> point[i];
		point[i] = abs(x - point[i]);
	}
	ll ans = point[0];
	for (int i = 1; i < n; i++) {
		ans = gcd(ans, point[i]);
	}
	cout << ans << endl;
	return 0;
}

