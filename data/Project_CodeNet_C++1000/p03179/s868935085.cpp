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

	string s;
	int n; cin >> n >> s;
	s = ">" + s;

	vector<int> memo(n+1), pref(n+1);

	function<int(int,int)> sum = [&] (int l, int r) {
		if(r < l) return 0;
		return (((pref[r] - (l ? pref[l-1] : 0)) % MOD) + MOD) % MOD;	
	};

	memo[0] = 1;
	for(int i=n-1; i>=0; i--) {
		pref[0] = memo[0];

		for(int j=1; j<=n; j++) pref[j] = (pref[j-1] + memo[j]) % MOD;

		for(int j=0; j <= n-i; j++) {
			if(s[i] == '>') memo[j] = sum(0, j-1);
			else memo[j] = sum(j, n-i-1);
		}
	}	

	cout << memo[n] << endl;

	return 0;
}
