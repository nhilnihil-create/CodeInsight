#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main() {
	int a, k, b;
	cin >> a>> b>> k;
	for (int i = 0; i < k; i++) {
		if (i % 2 == 0) {
			if (a % 2 == 1)a--;
			b += a / 2;
			a /= 2;
		}
		if (i % 2 == 1) {
			if (b % 2 == 1)b--;
			a += b / 2;
			b /= 2;
		}

	}
	cout << a << " " << b;
}