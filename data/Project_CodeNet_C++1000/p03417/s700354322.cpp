
#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long row, col;
	cin >> row >> col;
	cout << abs((row - 2) * (col - 2)) << endl;
	return 0;
}