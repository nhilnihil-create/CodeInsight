#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int a, b, c, k, sum;
	int n;

	cin >> a >> b >> c >> k;

	n = max({a, b,c});
	sum = n;

	for (int i=0; i < k; i++) {
		sum = sum * 2;
	}

	cout << a + b + c + sum - n << endl;

	return 0;
}