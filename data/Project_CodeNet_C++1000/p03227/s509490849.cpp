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

	if (S.size() == 2) {
		cout << S << endl;
	}
	else {
		for (int i = 2; i >= 0; i--) {
			cout << S.at(i);
		}
		cout << endl;
	}
}