#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cmath>
#include<math.h>
#include<bitset>
using namespace std;

int main() {
	int n; cin >> n;
	int d = n % 10; n /= 10; int c = n % 10; n /= 10; int b = n % 10; n /= 10;
	int a = n;
	for (int i = 0; i < (1 << 3); i++) {
		bitset<3>s(i);
		int sum = a;
		if (s.test(0))sum += b;
		else sum -= b;
		if (s.test(1))sum += c;
		else sum -= c;
		if (s.test(2))sum += d;
		else sum -= d;
		if (sum == 7) {
			cout << a;
			if (s.test(0))cout << '+';
			else cout << '-';
			cout << b;
			if (s.test(1))cout << '+';
			else cout << '-';
			cout << c;
			if (s.test(2))cout << '+';
			else cout << '-';
			cout << d << "=7" << endl;
			return 0;
		}
	}
}