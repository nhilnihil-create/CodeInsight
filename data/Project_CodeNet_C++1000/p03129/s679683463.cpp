#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	if ((n + 1) / 2 >= k) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}
