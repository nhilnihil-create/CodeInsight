#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int m;
	for (int i = 1; i * i <= n; i++) {
		m = i * i;
	}
	cout << m << endl;

	return 0;
}