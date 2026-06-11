#include "bits/stdc++.h"
using namespace std;

int main() {
	
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	
	int mcost = INT_MAX;
	for (int med=0; med<=2*max(x, y); med+=2) {
		int mx = max(0, x - med / 2);
		int my = max(0, y - med / 2);
		mcost = min(mcost, mx * a + my * b + med * c);
		// cout << med << ' ' << mx * a + my * b + med * c << endl;
	}
	
	cout << mcost << endl;
	
}
