#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	string S;
	cin >> S;

	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		if (S.at(i) == '1') cnt++;
	}

	cout << cnt << endl;
}