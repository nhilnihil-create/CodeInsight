#include "bits/stdc++.h"
using namespace std;
string s;	
const int inf = 100000000;
int mem[333][333][333];

int dp(int l, int r, int k) {
	if(k < 0) return -inf;
	if(l == r) return 1;
	if(l > r) {
		return 0;
	}
	if(mem[l][r][k] != -1) return mem[l][r][k];
	int ans = -inf;
	if(s[l] == s[r]) ans = max(ans, 2 + dp(l + 1, r - 1, k));
	ans = max(ans, dp(l + 1, r, k));
	ans = max(ans, dp(l, r - 1, k));
	ans = max(ans, 2 + dp(l + 1, r - 1, k - 1));
	return mem[l][r][k] = ans;
}

int main(int argc, char const *argv[])
{
	cin >> s;
	int k;
	cin >> k;
	memset(mem, -1, sizeof mem);
	cout << dp(0, s.size() - 1, k) << endl;
	return 0;
}