#include <iostream>
#include <string>
#include <vector>
using namespace std;

int digitsum(int n) {
	int sum = 0;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main()
{
	int n; cin >> n;
	int min = 1000000;
	for (int i = 1; i < n; i++) {
		int ds = 0;
		ds = digitsum(n - i) + digitsum(i);
		if (ds < min) min = ds;
	}
	cout << min << endl;
}