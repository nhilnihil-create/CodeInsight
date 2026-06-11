#include <iostream>
using namespace std;
int main() {
	long long n, m, a;
	cin >> n >> m;
	a = (n - 2) * (m - 2);
	cout << (a < 0 ? -a : a);
}