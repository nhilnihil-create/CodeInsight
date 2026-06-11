#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int> > s(m);
	REP(i, m) {
		int k; cin >> k;
		s[i].resize(k);
		REP(j, k) {
			cin >> s[i][j];
			s[i][j]--;
		}
	}
	vector<int> p(m);
	REP(i, m) cin >> p[i];

	int res = 0;
	REP(bit, (1 << n)) {
		bool ok = true;
		REP(j, m) {
			int cnt = 0;
			for (int id : s[j])
				if ((bit >> id) & 1)
					cnt++;
			cnt %= 2;
			if (cnt != p[j])
				ok = false;
		}
		if (ok) res++;
	}
	cout << res << '\n';
	return 0;
}
