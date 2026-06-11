#include <bits/stdc++.h>
const long long MOD = 1e9+7;
using namespace std;

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A,B,C;
	cin >> A >> B >> C;

	if (A==B && B==C && C==A) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}
