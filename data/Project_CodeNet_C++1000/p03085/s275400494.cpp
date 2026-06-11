#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	string b;
	cin >> b;

	for (int i = 0; i < b.size(); i++) {
		char ch = b[i];
		if (ch == 'A') cout << 'T';
		if (ch == 'T') cout << 'A';
		if (ch == 'G') cout << 'C';
		if (ch == 'C') cout << 'G';
	}
	cout << endl;
}