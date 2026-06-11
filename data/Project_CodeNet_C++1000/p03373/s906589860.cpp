#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;

	
	
	int mn = 1001001001;

	int m;

	for (int i = 0; i <= max(2*x,2*y); i = i + 2) {

		m = i * c + max(x - i/2, 0) * a + max(y - i/2, 0) * b;
		if (mn > m) {
			mn = m;
		}

	}
	cout << mn << endl;

	return 0;
}