#include"bits/stdc++.h"

#define rep(i, N) for(int i = 0;i < N;i++)
typedef long long ll;

using namespace std;

int main(void) {
	string S; cin >> S;
	int cnt = 0;
	ll ans = 0;

	rep(i, S.length()) {
		if (S[i] == 'W') {
			ans += i - cnt;
			cnt++;
		}
	}

	cout << ans << endl;

	return 0;
}