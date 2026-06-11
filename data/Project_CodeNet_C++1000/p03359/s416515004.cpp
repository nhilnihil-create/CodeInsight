#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	if (n <= m) {
		cout << n << endl;
	} else {
		cout << n - 1 << endl;
	}
	return 0;
}