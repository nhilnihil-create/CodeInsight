#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= 3500; i++) {
		for (int j = 1; j <= 3500; j++) {
			if ((ll)4 * i * j - n * j - n * i != 0) {
				if ((ll)n * i * j % (4 * i * j - n * j - n * i) == 0 && (ll)n * i * j / (4 * i * j - n * j - n * i) > 0) {
					cout << i << " " << j << " " << (ll)n * i * j / (ll)(4 * i * j - n * j - n * i) << endl;
					return 0;
				}
			}
		}
	}
}