#include <bits/stdc++.h>

using namespace std;

#define REP(i, N) for (int (i) = 0; (i) < (N); ++(i))
#define READALL(c) for (auto &e : c) { cin >> e; }
#define PRINTALL(c) for (const auto &e : c) { cout << e << "\t"; } cout << "\n";

template <typename T>
using V = vector<T>;

typedef long double ld;

int N;
string S;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> S;
	N = S.size();

	if (N%2 == 0) {
		int bs = 0;
		for (char c : S) bs ^= (1<<(c-'a'));
		if (!bs) {
			cout << 1 << endl;
			return 0;
		}
	}

	V<int> DP(1<<26, 1e9);
	DP[0] = 0;

	int bs = 0, res;

	REP(i, N) {
		bs ^= (1<<(S[i]-'a'));
		int ans = 1e9;
		REP(c, 26) ans = min(ans, DP[bs^(1<<c)]);
		// cout << i << " " << bs << " " << ans+1 << endl;
		DP[bs] = min(DP[bs], ans+1);
		res = ans+1;
	}

	cout << res << endl;
	
}