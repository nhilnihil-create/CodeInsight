#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	string S;
	cin >> N >> S;
	int cntb = 0, cntw = 0;
	int ans = INT_MAX;
	for (int i = 0; i < N; i++) {
		cntw += (S[i] == '.' ? 1 : 0);
	}
	for (int i = 0; i <= N; i++) {
		ans = min(ans, cntb + cntw);
		cntw -= (S[i] == '.' ? 1 : 0);
		cntb += (S[i] == '#' ? 1 : 0);
	}
	cout << ans << endl;
	return 0;
}
