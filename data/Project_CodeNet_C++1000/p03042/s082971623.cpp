#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
const int INF = 1 << 30;
const long long MOD = 1000000000 + 7;
const double PI = acos(-1);

int main() {
	string S; cin >> S;
	int num1 = atoi(S.substr(0, 2).c_str());
	int num2= atoi(S.substr(2).c_str());
	if (1<=num1 && num1<=12) {
		if (1 <= num2 && num2 <= 12)cout << "AMBIGUOUS";
		else cout << "MMYY";
	}
	else {
		if (1 <= num2 && num2 <= 12)cout << "YYMM";
		else cout << "NA";
	}
}