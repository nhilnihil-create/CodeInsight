#include <iostream>
#include <string>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int n;
	cin >> n;
	int i, i1, i2, i3, i4, i5, i6;
	for (i = 0; i < n; i++) {
		cout << a + i << endl;
		if (a + i >= b)
			break;
	}
	for (i1 = n; i1 > 0; i1--) {
		if (b - i1 +1 >= a + n)
			cout << b - i1 +1 << endl;
	}
	return 0;
}