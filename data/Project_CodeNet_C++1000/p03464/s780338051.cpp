#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx")
#include <bits/stdc++.h>
constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

bool isOK(ll x, vector<ll>& a) {
	ll cn = x;
	for (int i = 0; i < a.size(); i++) {
		cn = (cn / a[i]) * a[i];
	}
	return cn == 2;
}

int main() {
	ll N;
	cin >> N;
	vector<ll> a(N);
	for (int i = 0; i < N; i++)cin >> a[i];


	ll mx = 2;
	for (int i = N-1; i >= 0; i--) {
		mx = ((mx + a[i] - 1) / a[i]) * a[i];
	}
	
	ll cn = mx;
	for (int i = 0; i < N; i++) {
		cn = (cn / a[i]) * a[i];
	}
	if (cn != 2) {
		cout << -1 << endl;
		return 0;
	}

	ll ng = INF_LL/4; //「index = 0」が条件を満たすこともあるので、初期値は -1
	ll ok = mx; // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

	/* ok と ng のどちらが大きいかわからないことを考慮 */
	while (abs(ok - ng) > 1) {
		ll mid = (ok + ng) / 2;
		
		if (isOK(mid, a)) ok = mid;
		else ng = mid;
	}
	cout << mx << " " << ok << endl;

}