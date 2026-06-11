#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;

	for (int i = 1; i <= 9; i++) {
		int tmp = 111 * i;
		if (tmp < n) {
		}
		else{
			cout << tmp << endl;
			break;
		}
	}
	return 0;
}