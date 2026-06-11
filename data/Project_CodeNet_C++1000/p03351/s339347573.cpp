#include"bits/stdc++.h"
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << ((abs(a - b) > d || abs(b - c) > d ) && abs(c - a) > d ? "No" : "Yes") << endl;
	return 0;
}