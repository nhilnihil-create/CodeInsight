#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int a, b; cin >> a >> b;

	int sumLeft = 0;
	int sumRight = 1;
	for (int i = 1; i < 1000; i++) {
		sumLeft += i;
		sumRight += i + 1;
		for (int j = 1; j <= sumRight; j++) {
			if (sumLeft - j == a && sumRight - j == b) {
				cout << j << endl;
				return 0;
			}
		}
	}

	return 0;
}