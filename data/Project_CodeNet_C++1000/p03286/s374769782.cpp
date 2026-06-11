#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N;
	cin >> N;

	string b = "";
	while (N) {
		int s = N % 2;
		if (s < 0) s += 2;
		//cout << s << endl;
		if (s == 1) b.push_back('1');
		else b.push_back('0');
		N = (N - s) / -2;
	}

	if (b == "") b = '0';
	reverse(b.begin(), b.end());

	cout << b << endl;
}