#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

string s;
short dp[302][302][302];
int go(int l, int r, int k){
	if(l == r)
		return 1;
	if(l > r)
		return 0;
	if(dp[l][r][k] != -1)
		return dp[l][r][k];
	int ret = max(go(l + 1, r, k), go(l, r - 1, k));
	if(s[l] == s[r])
		ret = max(ret, go(l + 1, r - 1, k) + 2);
	else if(k)
		ret = max(ret, go(l + 1, r - 1, k - 1) + 2);
	return dp[l][r][k] = ret;
}

int main() {
	ios::sync_with_stdio(false);
	//	srand(time(NULL));
	int k; cin >> s >> k;
	memset(dp, -1, sizeof dp);
	cout << go(0, s.size() - 1, k) << endl;
	return 0;
}
