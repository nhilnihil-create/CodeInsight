#include <bits/stdc++.h> 
using namespace std; 
#define for_(i, s, e) for (int i = s; i < e; i++)
#define for__(i, s, e) for (ll i = s; i < e; i++)
#define SSTR(x) static_cast<std::ostringstream&>((std::ostringstream() << std::dec << x)).str()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
#define endl '\n'

int n;
vi nums;
vi dp;
int mn = 1e8;

int solve(int p) {
	if (dp[p] != -1) return dp[p];
	if (p < mn) return 0;
	
	int ans = 0;
	for (int i: nums) if (i <= p) {
		if (!solve(p-i)) ans = 1;
	}
	
	return dp[p] = ans;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("test.in", "r", stdin);
	#endif
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int k; cin >> n >> k;
	nums.resize(n); dp.resize(k+1, -1);
	for_(i, 0, n) cin >> nums[i];
	for (int i: nums) mn = min(mn, i);
	
	if (solve(k)) cout << "First";
	else cout << "Second";
	cout << endl;
	

	return 0;
}
