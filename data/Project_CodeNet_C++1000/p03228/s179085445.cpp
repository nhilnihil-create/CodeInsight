#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll a, b, k; cin >> a >> b >> k;
	for (int i = 0; i < k; i++) {
		if (i % 2 == 0) {
			if (a % 2 == 1) {
				a--;				
			}
			b += a / 2;
			a /= 2;
		}
		else {
			if (b % 2 == 1) {
				b--;
			}
			a += b / 2;
			b /= 2;
		}
	}	
	cout << a << " " << b << endl;
    return 0;
}