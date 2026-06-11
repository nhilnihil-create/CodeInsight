#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stdio.h>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double PI = 3.1415926535897932;

/* a と b の最大公約数を返す関数 */
long long GCD(long long a, long long b) {
	if (b == 0) return a;
	else return GCD(b, a % b);
}

// 目的の値の key index を返す
int binary_search(const vector<int>& vec, int key)
{
	int ng = -1;
	int ok = (int)vec.size();	// [index = a.size()-1]が条件を満たさないこと

	while (abs(ok - ng) > 1)
	{
		int mid = (ok + ng) / 2;

		if (vec[mid] <= key) {
			ok = mid;
		}
		else {
			ng = mid;
		}
	}

	return ok;
}

int main()
{
	int N;
	cin >> N;

	vector<int> Ai(N);
	vector<int> Bi(N);
	vector<int> Ci(N);
	rep(i, N) cin >> Ai[i];
	rep(i, N) cin >> Bi[i];
	rep(i, N) cin >> Ci[i];

	sort(Ai.begin(), Ai.end());
	sort(Bi.begin(), Bi.end());
	sort(Ci.begin(), Ci.end());

	ll ans = 0;
	for (int j = 0; j < N; ++j)
	{
		auto ita = lower_bound(Ai.begin(), Ai.end(), Bi[j]);
		auto itc = upper_bound(Ci.begin(), Ci.end(), Bi[j]);
		ans += (ita - Ai.begin()) * (Ci.end() - itc);
	}

	cout << ans << endl;
	return 0;
}