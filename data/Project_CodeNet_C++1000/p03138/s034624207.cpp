#pragma GCC optimize("O3")
//#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx2")
#define io_init cin.tie(0);ios::sync_with_stdio(0);cout<<setprecision(10)
#include <bits/stdc++.h>
constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

// 001
// 110
// 011

// 100
int main() {
	ll N, K;
	cin >> N >> K;
	vector<ll> cnt(64, 0);
	vector<ll> A(N);
	for (int i = 0; i < N; i++) {
		ll tmp;
		cin >> tmp;
		A[i] = tmp;
		for (int j = 0; j < 63; j++) {
			cnt[j] += (((1LL << j) & tmp) != 0);
		}
	}
	ll m = log2(K);
	ll ans = 0;
	ll a = 0;
	bool flag = true;
	for (int i = m; i >= 0; i--) {
		//cout << cnt[i] << endl;
		
		if (cnt[i] >= N - cnt[i]) {
			if ((K & (1LL << i)) != 0)flag = false;
		}
		else {
			if (flag && (K & (1LL << i)) == 0)continue;
			a += (1LL << i);
		}
	}
	for (int i = 0; i < N; i++) {
		ans += a ^ A[i];
	}
	//cout << a << endl;
	cout << ans << endl;
}
