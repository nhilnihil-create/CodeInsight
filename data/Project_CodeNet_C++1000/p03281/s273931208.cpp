#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int INF = 1001001001;

ll pow_mod(ll x, ll y) {
	ll res = 1;
	for (ll i = 0; i < y; i++) res = res * x % mod;
	return res;
}

int count(int n) {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) cnt++;
	}
	return cnt;
}

int main() {
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i+=2) {
		if (count(i) == 8) ans++;
	}
	cout << ans << endl;
	return 0;
}