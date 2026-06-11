#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

	int n; cin >> n;
	vector<ll> v(n), pref(n);
	for(ll& i : v) cin >> i;

	pref[0] = v[0];
	for(int i=1; i<n; i++) pref[i] = pref[i-1]+v[i];

	auto query = [&] (int l, int r) {return pref[r] - (l ? pref[l-1] : 0);};

	vector<vector<ll>> memo(n+1, vector<ll>(n)); // sz, start

	for(int sz = 2; sz <= n; sz++) {
		for(int i=0; i<=n-sz; i++) {
			memo[sz][i] = LINF;
			for(int sz2 = 1; sz2 < sz; sz2++)
				memo[sz][i] = min(memo[sz][i], memo[sz2][i] + memo[sz-sz2][i+sz2]);

			memo[sz][i] += query(i, i+sz-1);
		}
	}

	cout << memo[n][0] << endl;

	return 0;
}
