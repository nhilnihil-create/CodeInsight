#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	string S;
	cin >> S;

	int a = 0, b = 0;
	for (int i = 0; i < S.size(); i++) {
		if (i % 2) {
			if (S[i] != '0') a++;
		}
		else {
			if (S[i] != '1') a++;
		}
	}
	for (int i = 0; i < S.size(); i++) {
		if (i % 2) {
			if (S[i] != '1') b++;
		}
		else {
			if (S[i] != '0') b++;
		}
	}

	cout << min(a, b) << endl;
}