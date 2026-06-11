#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<map>
#include<math.h>
#include<queue>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
const int mod = 1000000007;
const int INF = 1000000000;
const long long LINF = 1e18;
const int MAX = 510000;
int main() {
	string s;
	int a, b, c, d;
	cin >>s;
	bool f1 = 0, f2 = 0, f3 = 0, f4 = 0, f5 = 0, f6 = 0, f7 = 0, f8 = 0;
	a = s[0] - '0';
	b = s[1] - '0';
	c = s[2] - '0';
	d = s[3] - '0';
		if (a + b + c + d == 7) { f1 = 1; }
		else if (a + b + c - d == 7) { f2 = 1; }
		else if (a + b - c + d == 7) { f3 = 1; }
		else if (a - b + c + d == 7) { f4 = 1; }
		else if (a + b - c - d == 7) { f5 = 1; }
		else if (a - b + c - d == 7) { f6 = 1; }
		else if (a - b - c + d == 7) { f7 = 1; }
		else if (a - b - c - d == 7) { f8 = 1; }

		if (f1 == 1) { cout << a << "+" << b << "+" << c << "+" << d << "=7" << endl; }
		if (f2 == 1) { cout << a << "+" << b << "+" << c << "-" << d << "=7" << endl; }
		if (f3 == 1) { cout << a << "+" << b << "-" << c << "+" << d << "=7" << endl; }
		if (f4 == 1) { cout << a << "-" << b << "+" << c << "+" << d << "=7" << endl; }
		if (f5 == 1) { cout << a << "+" << b << "-" << c << "-" << d << "=7" << endl; }
		if (f6 == 1) { cout << a << "-" << b << "+" << c << "-" << d << "=7" << endl; }
		if (f7 == 1) { cout << a << "-" << b << "-" << c << "+" << d << "=7" << endl; }
		if (f8 == 1) { cout << a << "-" << b << "-" << c << "-" << d << "=7" << endl; }


	return 0;
}