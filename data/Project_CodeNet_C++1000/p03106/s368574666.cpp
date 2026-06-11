#include <iostream>
using namespace std;

int main()
{
	int a, b, k, x;
	int count = 0;
	cin >> a >> b >> k;
	if (a < b) {
		x = b;
		b = a;
		a = x;
	}
	for (int i = a; i > 0; i--) {
		if (a%i == 0 && b % i == 0) {
			count++;
		}
		if (count == k) {
			cout << i << endl;
			return 0;
		}
	}
}