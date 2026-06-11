#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;

int main()
{
	int n, a, b;
	cin >> n >> a >> b;
	if (a <= b && a + b <= n) {
		cout << a << " " << 0 << endl;
	}
	else if (a > b && a + b <= n) {
		cout << b << " " << 0 << endl;
	}
	else if (a <= b && a + b > n) {
		cout << a << " " << a + b - n << endl;
	}
	else {
		cout << b << " " << a + b - n << endl;
	}
}