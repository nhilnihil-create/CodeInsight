#include "bits/stdc++.h"
using namespace std;

int main() {
	string S;
	cin >> S;
	static long long SUM[200010];
	map<long long, long long> mp;
	SUM[0] = 0;
	mp[0] = 1;
	for (int i = 0; i < S.size(); i++) {
		SUM[i + 1] = SUM[i] ^ (1 << (S[i] - 'a'));
	}
	if (SUM[S.size()] == 0) {
		cout << 1 << endl;
		return 0;
	}
	for (int i = 1; i <= S.size(); i++) {
		long long X = 1000000000;
		if (mp[SUM[i]] != 0) X = mp[SUM[i]];
		for (int j = 0; j < 26; j++) {
			long long Y = SUM[i] ^ (1 << j);
			if (mp[Y] != 0) X = min(X, mp[Y]);
		}
		if (mp[SUM[i]] == 0) mp[SUM[i]] = X + 1;
		else mp[SUM[i]] = min(mp[SUM[i]], X + 1);
	}
	cout << mp[SUM[S.size()]] - 1 << endl;
}