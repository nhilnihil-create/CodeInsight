#include"bits/stdc++.h"

#define rep(i, N) for(int i = 0;i < N;i++)
typedef long long ll;
const int mod = 1e9 + 7;

using namespace std;

int main(void) {
	int n; cin >> n;
	string S; cin >> S;
	int ans = 0;

	for (int i = 1; i < S.length(); i++) {
		string A = S.substr(0, i), B = S.substr(i, S.length());
		map<char, bool> a, b;

		for (char x : A)a[x] = true;
		for (char x : B)b[x] = true;

		int cnt = 0;
		for (auto x : a)if (b.count(x.first) != 0)cnt++;
		ans = max(ans, cnt);
	}

	cout << ans << endl;

	return 0;
}