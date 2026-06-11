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

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
	int N, C;
	cin >> N >> C;
	int x[N], v[N];
	rep(i, N) cin >> x[i] >> v[i];

	int vsum1[N + 1] = {};
	int vsum2[N + 1] = {};
	rep(i, N) vsum1[i + 1] = vsum1[i] + v[i];
	rep(i, N) vsum2[i + 1] = vsum2[i] + v[N - 1 - i];

	int Lsum[N + 1] = {};
	int LsumM[N + 1] = {};

	rep(i, N) Lsum[i + 1] = vsum1[i + 1] - x[i];
	rep(i, N) LsumM[i + 1] = max(LsumM[i], Lsum[i + 1]);


	int Rsum[N + 1] = {};
	int RsumM[N + 1] = {};
	rep(i, N) Rsum[i + 1] = vsum2[i + 1] - (C - x[N - 1 - i]);
	rep(i, N) RsumM[i + 1] = max(RsumM[i], Rsum[i + 1]);
	// cout << endl;
	// rep(i, N + 1) cout << LsumM[i] << " " <<Lsum[i] << " " << RsumM[i] << " " << Rsum[i] << endl;

	int ans = max(LsumM[N], RsumM[N]);
	// dump(ans);
	REP(i, 1, N) {
		int tmp1 = LsumM[N - i] + Rsum[i] - (C - x[N - i]);
		int tmp2 = RsumM[N - i] + Lsum[i] - x[i - 1];
		ans = max(ans, tmp1);
		ans = max(ans, tmp2);
		// dump(ans);
	}
	cout << ans << endl;


    return 0;
}
