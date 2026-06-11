//#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

#define rep(i,n) for(ll (i)=0;(i)<(ll)(n);(i)++)
#define all(x) (x).begin(),(x).end()

#define MOD 1000000007LL
#define INF (1LL<<60LL)
#define int long long
#define MAX_N (100001)
typedef long long ll;

using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int ans = 0;
	rep(i, 2) {
		int a, b; cin >> a >> b;
		ans += min(a, b);
	}
	cout << ans << endl;

}