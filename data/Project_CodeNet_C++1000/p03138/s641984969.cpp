#pragma GCC optimize("O3")
//#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx2")
#define io_init cin.tie(0);ios::sync_with_stdio(0);cout<<setprecision(20)
#include <bits/stdc++.h>
constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int main() {
	ll N, K;
	cin >> N >> K;
	vector<ll> A(N);
	for (int i = 0; i < N; i++)cin >> A[i];
	vector<ll> cnt(63, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 63; j++)if (A[i] & (1LL << j))cnt[j]++;
	}
	ll ans = 0;
	bool flag = 0; //K未満フラグ
	for (ll j = 62; j >= 0; j--) {
		if (cnt[j] < N - cnt[j]) { //立てた方が得
			if (!flag && ((K & (1LL << j)) == 0) )ans += (1LL << j) * cnt[j]; //立てられない
			else ans += (1LL << j) * (N - cnt[j]);
		}
		else { //立てない方が得
			if (!flag && ((K & (1LL << j)) != 0) ) {
				flag = true;
			}
			ans += (1LL << j) * cnt[j];
		}
	}
	cout << ans << endl;
}