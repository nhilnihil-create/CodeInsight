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

	int ans = INF;
	for (int i = 0; i < S.size() - 2; i++) {
		string s = S.substr(i, 3);
		int n = stoi(s);
		int d = abs(753 - n);
		ans = min(ans, d);
	}

	cout << ans << endl;
}