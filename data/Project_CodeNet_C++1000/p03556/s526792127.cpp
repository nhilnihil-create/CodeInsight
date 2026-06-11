#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
	ll n;
	cin >> n;
	ll j = 1,ans=1;
	
	for (ll i = 1; i < n; i++) {
		j = i * i;
		if (j <= n) {
			ans = j;
		}
		else {
			break;
		}
	}
	cout << ans << endl;
}
