#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int a, b, k, num = 0;
	int order = 1;
	cin >> a >> b >> k;

	for (int i = min(a, b); i > 0; i--) {
		if (a % i == 0 && b % i == 0) {
			if (order == k) {
				num = i;
				break;
			}
			else order++;
		}
	}

	cout << num << endl;

	return 0;
}
