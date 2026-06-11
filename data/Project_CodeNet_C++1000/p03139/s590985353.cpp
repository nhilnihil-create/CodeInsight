#include <iostream>

using namespace std;

int main()
{
	int n, a, b;
	int max, min;

	cin >> n >> a >> b;

	if (a < b) max = a;
	else max = b;

	min = n - a - b;
	if (min > 0) {
		min = 0;
	}
	else {
		min = -min;
	}

	cout << max << " " << min << endl;
}