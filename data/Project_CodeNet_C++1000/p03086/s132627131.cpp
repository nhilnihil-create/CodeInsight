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

	int ans = 0;
	int cnt = 0;

	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'A') cnt++;
		else if (S[i] == 'C') cnt++;
		else if (S[i] == 'G') cnt++;
		else if (S[i] == 'T') cnt++;
		else {
			ans = max(ans, cnt);
			cnt = 0;
		}
		if (i == S.size() - 1) ans = max(ans, cnt);;
	}

	cout << ans << endl;
}