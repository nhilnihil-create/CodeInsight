#include <bits/stdc++.h>
using namespace std;
typedef pair <string, string> pss;
typedef pair <int, int> pii;

#define int long long

const int N = 18 + 1, base = 31, mod = 1e17 + 7, bbase = 17;
int n, ans;
string s1, s2, s;
map <pii, int> mp;

int get_hs(string &ss) {
	int res = 0;
	for (char c : ss)
		res = ((base * res) + (c - 'a')) + 1;
	return res;
}

void solve(int msk) {
	string tmp1, tmp2;
	for (int i = n - 1; i >= 0; i--)
		if (msk & (1LL << i))
			tmp1 += s[n + i];
		else
			tmp2 += s[n + i];
	
	mp[pii(get_hs(tmp1), get_hs(tmp2))]++;
}

void solve2(int msk) {
	string tmp1, tmp2;
	for (int i = 0; i < n; i++)
		if (msk & (1LL << i))
			tmp1 += s[i];
		else
			tmp2 += s[i];
	
	ans += mp[pii(get_hs(tmp1), get_hs(tmp2))];
}

int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		s1 += s[i];
	for (int i = n; i < n; i++)
		s2 += s[i];
	
	for (int msk = 0; msk < (1LL << n); msk++)
		solve(msk);
	
	for (int msk = 0; msk < (1LL << n); msk++)
		solve2(msk);
	cout << ans;
}