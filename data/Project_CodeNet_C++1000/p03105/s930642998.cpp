#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int count = b / a;
	if (c > count) {
		cout << count << endl;
	}
	else {
		cout << c << endl;
	}
}