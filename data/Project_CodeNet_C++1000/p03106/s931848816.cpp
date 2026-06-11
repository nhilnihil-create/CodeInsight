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

int main() {
	int a, b, k;
	cin >> a >> b >> k;
	int c = min(a, b);
	int cnt = 0;
	while (cnt < k) {
		if (a % c == 0 && b % c == 0) {
			cnt++;
		}
		c--;
	}
	c++;
	cout << c << endl;
	return 0;
}