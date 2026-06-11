#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	char X, Y;
	cin >> X >> Y;

	if (X == Y) cout << '=';
	if (X < Y) cout << '<';
	if (X > Y) cout << '>';
	cout << endl;
}