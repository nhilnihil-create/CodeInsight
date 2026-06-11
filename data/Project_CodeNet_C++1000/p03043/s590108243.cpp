#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long
int main() {

	long double n, k;
	cin >> n >> k;
	long double p = 0.0;
	for (int i = 1; i <= n; i++) {
		int a = i;
		long double pi = 1.0 / (long double) n;
		while (a < k) {
			pi *= 0.5;
			a *= 2;
		}
		p += pi;
	}
	cout << fixed << setprecision(9) << p << endl;
}
