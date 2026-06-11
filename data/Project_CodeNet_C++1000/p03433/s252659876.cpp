#include <iostream>
using namespace std;

int main() {
	int n, a, b, c;

	cin >> n;
	cin >> a;

	b = n / 500;
	c = n - (500 * b);

	if(c <= (1 * a)){
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}