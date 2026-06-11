#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	ll x = 0;
	for (int i = 0; i < n; i++) {
		int y;
		cin >> y;
		x += y - 1;
	}
	cout << x << endl;
}