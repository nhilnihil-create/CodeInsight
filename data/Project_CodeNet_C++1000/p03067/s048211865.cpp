#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <stack>
#include <vector>
#include <stdio.h>
using namespace std;

int a[3], b;

int main() {

	cin >> a[0] >> a[1] >> a[2];
	b = a[2];
	sort(a, a + 3);

	if (a[1] == b)cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}