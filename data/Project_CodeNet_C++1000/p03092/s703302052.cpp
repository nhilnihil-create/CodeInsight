#include <bits/stdc++.h>
using namespace std;
#define makefast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define int long long

const int N = 5e3 + 7;

int dp[N][N];
int n, a, b;
int p[N], pnt[N];

int32_t main() {
	makefast;
	cin >> n >> a >> b;
	for (int i = 1; i <= n; i++)
		cin >> p[i], pnt[p[i]] = i;
	set <int> s;
	s.insert(0);
	for (int i = n; i >= 1; i--) {
		s.insert(p[i]);
		auto it = s.rbegin();
		int lst = *it;
		int mn = pnt[lst];
		int x = lst;
		int cnt = 0;
		it++;
		while (it != s.rend()) {
			//	cout << endl << endl << i << " LST : " << lst << " X : " << x << " " << cnt << endl;
			for (int j = lst; j > *it; j--) {
				dp[i][j] = min(dp[mn + 1][lst] + a, dp[mn + 1][x + 1] + b * cnt);
				//		cout << i << " " << j << " > " << dp[i][j] << " " << dp[mn + 1][1] + a << " & " << dp[mn + 1][x + 1] + b * cnt << endl;
			}
			lst = *it;
			if (lst == 0)
				break;
			if (pnt[lst] < mn) {
				mn = pnt[lst];
				x = lst;
				cnt = 0;
			}
			else	
				cnt++;
			it++;
		}
	}
	cout << dp[1][1];

	return 0;
}

