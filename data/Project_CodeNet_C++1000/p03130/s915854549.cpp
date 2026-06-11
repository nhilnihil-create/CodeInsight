#include <iostream>

using namespace std;

int main()
{
	int a[3][2];

	cin >> a[0][0] >> a[0][1];
	cin >> a[1][0] >> a[1][1];
	cin >> a[2][0] >> a[2][1];

	if (a[0][0] == a[1][0] || a[0][0] == a[1][1]) {
		if (a[0][0] == a[2][0] || a[0][0] == a[2][1]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	else if (a[0][1] == a[1][0] || a[0][1] == a[1][1]) {
		if (a[0][1] == a[2][0] || a[0][1] == a[2][1]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}