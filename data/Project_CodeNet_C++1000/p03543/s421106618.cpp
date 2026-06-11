#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;
	int n1, n2, n3;
	cin >> n;
	n1 = n / 1000;
	n = n - n1 * 1000;
	n2 = n / 100;
	n = n - n2 * 100;
	n3 = n / 10;
	n = n - n3 * 10;

	if (n2 == n3 && (n1 == n2 || n3 == n))cout << "Yes" << endl;
	else cout << "No" << endl;
}