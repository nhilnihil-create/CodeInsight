#include <bits/stdc++.h>

#ifdef NON_SUBMIT
#define TEST(n) (n)
#else
#define TEST(n) ((void)0)
#endif

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	TEST(freopen("input.txt", "r", stdin));
	TEST(freopen("output.txt", "w", stdout));
	TEST(freopen("debug.txt", "w", stderr));
	int T, A, B, rtV, s, e;
	long long V, ans;
	for (cin >> T; T; T--) {
		cin >> A >> B;
		if (A == 1 && B == 1) {
			cout << "0\n";
			continue;
		}
		V = 1LL * A*B - 1;
		s = 1, e = 1e9;
		while (s <= e) {
			int m = (s + e) >> 1;
			if (1LL * m*m <= V) s = m + 1;
			else e = m - 1;
		}
		ans = 2 * (rtV = e);
		if (rtV == V / rtV) ans--;
		if (A <= rtV) ans--;
		if (B <= rtV) ans--;
		cout << ans << '\n';
	}
	return 0;
}