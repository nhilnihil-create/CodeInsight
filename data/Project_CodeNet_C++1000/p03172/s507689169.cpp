#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9+7;

int main(){ _
	int n, k; cin >> n >> k;
	vector<int> v(n);
	for(int& i : v) cin >> i;
	
	vector<int> memo(k+1), pref(k+1);

	auto query = [&] (int l, int r) {
		int ret = pref[r];
		if(l) ret -= pref[l-1];
		return (ret + MOD) % MOD;
	};

	memo[0] = 1;
	for(int i=0; i<n; i++) {
		pref[0] = memo[0];
		for(int j=1; j<k+1; j++) pref[j] = (pref[j-1]+memo[j]) % MOD;

		for(int j=0; j<=k; j++)
			memo[j] = query(max(0, j-v[i]), j);
	}

	cout << memo[k] << endl;

	return 0;
}
