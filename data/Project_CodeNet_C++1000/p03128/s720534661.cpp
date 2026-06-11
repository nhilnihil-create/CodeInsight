#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };
const string nr[10] = { "0","1","2","3","4","5","6","7","8","9" };


bool larger(string a, string b) {
	int i;
	if (a.size() > b.size()) {
		return true;
	}
	if (a.size() < b.size()) {
		return false;
	}
	for (i = 0; i < a.size(); i++) {
		if (a[i] > b[i]) {
			return true;
		}
		if (a[i] < b[i]) {
			return false;
		}
	}
	return false;
}

int main(void) {
	int n, m, i, j, ain;
	const int nus[10] = { 0,2,5,5,4,5,6,3,7,6 };
	vector<int> a;
	string dp[10003], lk;
	
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d", &ain);
		a.push_back(ain);
	}

	for (i = 0; i <= n; i++) {
		dp[i] = "0";
	}
	
	for (i = 2; i <= n; i++) {
		for (j = 0; j < m; j++) {
			if (i < nus[a[j]] || (i - nus[a[j]] > 0 && dp[i - nus[a[j]]] == "0")) {
				continue;
			}
			lk = dp[i - nus[a[j]]] + nr[a[j]];
			if (larger(lk, dp[i])) {
				dp[i] = lk;
			}
		}
	}

	cout << dp[n].substr(1, dp[n].size() - 1) << '\n';

	return 0;
}