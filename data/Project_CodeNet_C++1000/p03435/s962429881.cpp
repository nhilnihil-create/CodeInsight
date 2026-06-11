#include <iostream>
using namespace std;

int main() {
	int c[3][3];
	int a, b;
	for (a = 0; a < 3; ++a)
		for (b = 0; b < 3; ++b)
			cin >> c[a][b];

	bool flag = true;
	for (a = 0; a < 2; ++a)
		for (b = 0; b < 2; ++b)
			if (c[a][b] - c[a][b + 1] != c[a + 1][b] - c[a + 1][b + 1])
				flag = false;

	cout << (flag ? "Yes" : "No") << endl;
}