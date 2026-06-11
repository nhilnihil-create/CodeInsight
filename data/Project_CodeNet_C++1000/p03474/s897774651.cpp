#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int A, B;
	string S;
	cin >> A >> B >> S;

	bool f = true;
	int len = A + B + 1;

	if (S.size() != len) {
		f = false;
	}
	else {
		for (int i = 0; i < S.size(); i++) {
			if (i == A) {
				if (S.at(i) != '-') {
					f = false;
					break;
				}
			}
			else {
				if (S.at(i) == '-') {
					f = false;
					break;
				}
			}
		}
	}

	cout << (f ? "Yes" : "No") << endl;
}