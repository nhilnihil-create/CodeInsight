#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	string s;
	cin >> s;

	int a, b, c;
	a = 0;
	b = 0;
	c = 0;

	for (int i = 0; i < 3; i++) {
		if (s.at(i) == 'a') a++;
		if (s.at(i) == 'b') b++;
		if (s.at(i) == 'c') c++;
	}

	if (a && b && c) cout << "Yes" << endl;
	else cout << "No" << endl;
}