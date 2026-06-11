#include <bits/stdc++.h>
#define int long long
#define bp __builtin_popcountll
#define pb push_back
#define in(s) freopen(s, "r", stdin);
#define out(s) freopen(s, "w", stdout);
#define inout(s, end1, end2) freopen((string(s) + "." + end1).c_str(), "r", stdin),\
		freopen((string(s) + "." + end2).c_str(), "w", stdout);
#define fi first
#define se second
#define bw(i, r, l) for (int i = r - 1; i >= l; i--)
#define fw(i, l, r) for (int i = l; i < r; i++)
#define fa(i, x) for (auto i: x)
using namespace std;
const int mod = 1e9 + 7, inf = 1061109567;
const long long infll = 4557430888798830399;
const int N = 1e6 + 5;
int n, q, cnt[N][3], cntM[N], prfSum[N];
string s;
int getID(char c) {
	if (c == 'D') return 0;
	if (c == 'M') return 1;
	if (c == 'C') return 2;
	return -1;
}
int getCnt(int l, int r, char c) {
	l = max(l, 0ll);
	r = min(r, n - 1);
	int id = getID(c);
	return cnt[r][id] - (l ? cnt[l - 1][id] : 0);
}
int getPrfSum(int l, int r) {
	l = max(l, 0ll);
	r = min(r, n - 1);
	return prfSum[r] - (l ? prfSum[l - 1] : 0);
}
signed main() {
	#ifdef BLU
	in("blu.inp");
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> s >> q;
	fw (i, 0, n) {
		fw (j, 0, 3) cnt[i][j] = i ? cnt[i - 1][j] : 0;
		if (getID(s[i]) != -1) cnt[i][getID(s[i])]++;
	}
	fw (i, 0, n) {
		if (s[i] != 'C') cntM[i] = 0;
		else cntM[i] = cnt[i][getID('M')];
	}
	fw (i, 0, n) prfSum[i] = (i ? prfSum[i - 1] : 0) + cntM[i];
	while (q--) {
		int k;
		cin >> k;
		//Fix d at pos x. Count number of indices i, j so that x < i < j < x + k by inclusion - exclusion.
		int ans = 0;
		fw (i, 0, n) if (s[i] == 'D') {
//			cout << "i = " << i << "\n";
			int cntC = getCnt(i, i + k - 1, 'C');
			int cntMC = getPrfSum(i, i + k - 1);
			//Now get rid of cases which M lies below i.
			int mBelow = cnt[i][getID('M')] * cntC;
			ans += cntMC - mBelow;
//			cout << "CntC = " << cntC << " cntMC = " << cntMC << " mBelow = " << cnt[i][getID('M')] << "\n";
		}
		cout << ans << "\n";
	}
	return 0;
}