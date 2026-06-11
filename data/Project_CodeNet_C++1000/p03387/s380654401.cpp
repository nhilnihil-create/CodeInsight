#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int d = 3 * max(max(a, b), c) - a - b - c;
	cout << (d % 2 ? d / 2 + 2 : d / 2);
}
