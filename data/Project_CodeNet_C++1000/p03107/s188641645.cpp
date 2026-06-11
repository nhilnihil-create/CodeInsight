#include "bits/stdc++.h"
using namespace std;

//25
typedef long long ll;

ll power(ll a , ll b) {
    ll ans = 1;
	while (b) {
		if (b & 1) {
			ans = ans  * a;
		}
		a = a * a;
		b  /= 2;
	}
	return ans;
}

int main() {
	string s;
	cin >> s;
	int n = (int)s.size();
	int a = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '1') a++;
	}
	cout << min(a * 2, 2 * (n - a));
} 	

