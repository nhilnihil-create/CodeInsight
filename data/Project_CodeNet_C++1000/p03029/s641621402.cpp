#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

const int INF = 1001001001;
const int mod = 1000000007;

ll pow(ll base, ll order) {
	ll ans = 1;
	rep(i,order - 1) ans *= base;
	return ans;
}

int gcd(int a, int b) {
	if (a < b) {
		int c = a;
		a = b;
		b = c;
	}
	if (b == 0) return a;
	return gcd (b, a % b);
}

int main() {
	int a, p;
	cin >> a >> p;

	int ans = 0;
	p += 3*a;
	ans = p/2;
	cout << ans << endl;
	
	return 0;
} 