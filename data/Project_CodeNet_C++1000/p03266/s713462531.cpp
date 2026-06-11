#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	long long a = n / k, b = (n + k / 2) / k;
	cout << (k % 2 ? a * a * a : a * a * a + b * b * b) << endl;
	return 0;
}