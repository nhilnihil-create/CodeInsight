#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cmath>
#include<math.h>
using namespace std;

int main() {
	int a, b, k;
	cin >> a >> b >> k;
	for (int i = a; i > 0; i--) {
		if (a % i == 0 && b % i == 0)k--;
		if (k == 0) {
			cout << i;
			return 0;
			break;
		}
	}
}