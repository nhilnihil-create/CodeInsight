#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair < int, int >;

const ll inf = 1e18L + 5;

vector < vector < int > > a;
vector < ll > group_value;
vector < ll > dp;

void f (int mask, int i, vector < int > & not_selected, int group, ll value) {
	if (i == (int) not_selected.size()) {
		dp[mask] = max (dp[mask], value + group_value[group]);
		return;
	}
	
	f (mask, i + 1, not_selected, group, value);
	f (mask ^ (1 << not_selected[i]), i + 1, not_selected, group ^ (1 << not_selected[i]), value);
}
	

int main() {
	int n; scanf ("%d", &n);
	a.resize (n, vector < int > (n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <n; j++) {
			scanf ("%d", &a[i][j]);
		}
	}
	group_value.resize (1 << n);
	for (int state = 0; state < (1 << n); state++) {
		vector < int > members;
		for (int i = 0; i < n; i++) {
			if ((state >> i) & 1) {
				members.push_back (i);
			}
		}
		for (int i = 0; i < (int) members.size(); i++) {
			for (int j = i + 1; j < (int) members.size(); j++) {
				group_value[state] += a[members[i]][members[j]];
			}
		}
	}
	dp.resize (1 << n, -inf);
	dp[0] = 0;
	for (int taken = 0; taken < (1 << n); taken++) {
		vector < int > not_taken;
		for (int i = 0; i < n; i++) {
			if (!((taken >> i) & 1)) {
				not_taken.push_back (i);
			}
		}
		f (taken, 0, not_taken, 0, dp[taken]);
	}
	printf ("%lld\n", dp[(1 << n) - 1]);
	return 0;
}

