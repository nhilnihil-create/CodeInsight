#include <bits/stdc++.h>
using namespace std;
typedef pair <string, string> pss;
typedef long long ll;

const int N = 18 + 1;
int n;
ll ans;
string s1, s2, s;
map <pss, int> mp;

void solve(int msk) {
	string tmp1, tmp2;
	for (int i = 0; i < n; i++)
		if (msk & (1LL << i))
			tmp1 += s[n + i];
		else
			tmp2 += s[n + i];
	
	reverse(tmp1.begin(), tmp1.end());
	reverse(tmp2.begin(), tmp2.end());
	mp[pss(tmp1, tmp2)]++;
}

void solve2(int msk) {
	string tmp1, tmp2;
	for (int i = 0; i < n; i++)
		if (msk & (1LL << i))
			tmp1 += s[i];
		else
			tmp2 += s[i];
	
	ans += mp[pss(tmp1, tmp2)];
}

int main() {
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