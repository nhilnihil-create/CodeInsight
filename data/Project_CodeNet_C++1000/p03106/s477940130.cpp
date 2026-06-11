#include<iostream>

using namespace std;

int main() {

	int a, b, k;

	cin >> a >> b >> k;
	int cnt = 0;
	int x;
	if (a > b) {
		x = a;
	}
	else {
		x = b;
	}
	while (1) {

		if (a % x == 0 && b % x == 0)cnt++;
		if (cnt == k)break;
		x--;
	}
	cout << x << endl;
	return 0;

}