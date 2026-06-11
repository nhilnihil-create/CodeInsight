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
	int n; cin >> n;
	vector<int> a(n+2);
	for (int i = 1; i < n+1; i++)cin >> a[i];
	a[0] = a[n + 1] = 0;
	int ans = 0;
	rep(i,n+1){
		ans += abs(a[i] - a[i + 1]);
	}
	for (int i = 1; i < n + 1; i++) {
		cout << ans - (abs(a[i + 1] - a[i]) + abs(a[i] - a[i - 1])) + abs(a[i + 1] - a[i - 1]);
		if (i < n) cout << " ";
		else cout << endl;
	}
}