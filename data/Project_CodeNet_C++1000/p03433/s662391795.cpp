#include<iostream>

using namespace std;

int main(void) {

	int n = 0, a = 0, n1, n2;

	cin >> n >> a;

	n1 = n / 500;

	n2 = n - (500 * n1);

	if (n2 <= a) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}