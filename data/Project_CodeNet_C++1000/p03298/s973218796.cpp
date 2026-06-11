#include <bits/stdc++.h>
using namespace std;
typedef pair <string, string> pss;

#define int long long

const int N = 18 + 1;
int n, ans;
string s1, s2, s;
map <pss, int> mp;

pss solve(int msk) {
	string tmp1, tmp2;
	for (int i = 0; i < n; i++)
		if (msk & (1LL << i))
			tmp1 += s[n + i];
		else
			tmp2 += s[n + i];
	
	reverse(tmp1.begin(), tmp1.end());
	reverse(tmp2.begin(), tmp2.end());
	return pss(tmp1, tmp2);
}

pss solve2(int msk) {
	string tmp1, tmp2;
	for (int i = 0; i < n; i++)
		if (msk & (1LL << i))
			tmp1 += s[i];
		else
			tmp2 += s[i];
	
	return pss(tmp1, tmp2);
}

int32_t main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		s1 += s[i];
	for (int i = n; i < n; i++)
		s2 += s[i];
	
	for (int msk = 0; msk < (1LL << n); msk++) {
		pss p = solve(msk);
//		cout << p.first << " " << p.second << endl;
		mp[p]++;
	}
	
	for (int msk = 0; msk < (1LL << n); msk++) {
		pss p = solve2(msk);
		ans += mp[p];
	}
	cout << ans;
}