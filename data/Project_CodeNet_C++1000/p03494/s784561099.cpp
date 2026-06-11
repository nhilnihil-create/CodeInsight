#include <iostream>
using namespace std;

int main() {
	int n;
	int a[200];

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	int count = 0;
	bool b = true;
	while (true) {
		for (int i = 0; i < n; i++) {
			if ((a[i] % 2) != 0) {
				b = false;
				break;
			}
		}
		if (b == false) break;
		else {
			count++;
			for (int i = 0; i < n; i++) a[i] /= 2;
		}
	}
	cout << count << endl;
}