#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(void) {
	int n, a, b;

	cin >> n >> a >> b;

	if (((b - a) & 1) == 1) {
		cout << "Borys" << endl;
	}
	else {
		cout << "Alice" << endl;
	}

	return 0;
}