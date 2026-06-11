#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
	vector<char> x(3);
	rep(i, 3) {
		cin >> x[i];
	}
	int normal = 700;
	if (x[0] == 'o') {
		normal += 100;
	}
	if (x[1] == 'o') {
		normal += 100;
	}
	if (x[2] == 'o') {
		normal += 100;
	}
	cout << normal << endl;
}