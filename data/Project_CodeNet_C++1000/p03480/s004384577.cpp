#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i, n) for (int i = 0; i < (int)n; i++)

int main()
{
	string S;
	cin >> S;
	int len = S.length();

	int ans = len;
	for (int i = 1; i < len; i += 1) {
		if (S[i] != S[i - 1]) {
			int v = max(i, len - i);
			ans = min(ans, v);
		}
	}
	cout << ans << endl;
	return 0;
}
