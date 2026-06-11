#include <bits/stdc++.h>

using namespace std;

int table[3005][3005], direction[3005][3005], highest = 0, hi = 0, hj = 0;
string s, t, ans = "";

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> s >> t;
	for (int i=1;i<=s.length();++i) {
		for (int j=1;j<=t.length();++j) {
			if (s[i-1] == t[j-1]) table[i][j] = table[i-1][j-1]+1;
			else if (table[i-1][j] > table[i][j-1]) { table[i][j] = table[i-1][j]; direction[i][j] = 1; }
			else { table[i][j] = table[i][j-1]; direction[i][j] = 2; }
			if (table[i][j] > highest) {
				highest = table[i][j];
				hi = i, hj = j;
			}
		}
	}
	while (hi > 0 && hj > 0) {
		if (s[hi-1] == t[hj-1]) ans = ans + s[hi-1];
		if (direction[hi][hj] == 0) { hi--; hj--; }
		else if (direction[hi][hj] == 1) hi--;
		else hj--;
	}
	reverse(ans.begin(),ans.end());
	cout << ans << '\n';
	return 0;
}