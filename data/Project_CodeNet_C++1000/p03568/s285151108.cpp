#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	ll x = 1;
	for (int i = 0; i < n; i++) {
		int y;
		cin >> y;
		if (y % 2 == 0)x *= 2;
	}
	cout << pow(3,n)-x << endl;
}