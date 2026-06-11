#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long int

typedef pair<int, int > P;

signed main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	int ans = 0;
	vector<int> L(N + 1);
	vector<int> R(N + 1);
	rep(i, N) cin >> L[i] >> R[i];
	L[N] = 0;
	R[N] = 0;
	sort(L.begin(), L.end(), greater<int>());
	sort(R.begin(), R.end());
	rep(i, N + 1) {
		ans += 2 * max(0LL, (L[i] - R[i]));
	}



	cout << ans << endl;


	return 0;
}
