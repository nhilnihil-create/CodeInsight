#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int min = 100000;

	int n, x;
	cin >> n >> x;

	int wei = x;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		if (m < min) min = m;
		wei -= m;
	}
	cout << n + wei / min << endl;
}