#include "bits/stdc++.h"

using namespace std;

int main() {
	long long X, Y;
	cin >> X >> Y;
	int ans = 0;
	while (Y>=X) {
		ans++;
		Y /= 2;
	}
	cout << ans <<endl;
	return 0;
}
