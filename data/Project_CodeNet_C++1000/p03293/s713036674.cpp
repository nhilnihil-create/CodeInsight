#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	string S, T;
	cin >> S >> T;

	for (int i = 0; i < S.size(); i++) {
		S = S.back() + S.substr(0, S.size() - 1);
		if (S == T) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}