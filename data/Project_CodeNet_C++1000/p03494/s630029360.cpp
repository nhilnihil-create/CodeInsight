#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[220];
	for (int i = 0; i < n; ++i) cin >> a[i];
	int count = -1;
	bool flag = true;
	while (flag) {
		for (int i = 0; i < n; ++i) {
			if (a[i] % 2 != 0) {
				flag = false;
			}
			a[i] /= 2;
		}
		++count;
	}

	cout << count << endl;
}