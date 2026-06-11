#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define FOR(i,a,n) for(int i=a;i<n;i++)

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 100005;

ll dp[MAX];
int n, k;
vector<int> v;

ll solve(int pos) {
	if(pos == n-1) return 0;
	if(pos >= n) return LINF;
	if(dp[pos] != -1) return dp[pos];

	ll res = LINF;
	FOR(i,1,k+1) {
		if(pos+i >= n) continue;
		res = min(res, abs(v[pos] - v[pos+i]) + solve(pos+i));
	}

	return dp[pos] = res;
}

int main() { _
	cin >> n >> k;
	v.resize(n);
	FOR(i,0,n) cin >> v[i];

	memset(dp, -1, sizeof(dp));

	cout << solve(0) << endl;
	return 0;
}
