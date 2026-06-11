#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	if (n / 2 + !!(n % 2) < k) cout << "NO" << endl;
	else cout << "YES" << endl;

	return 0;
}