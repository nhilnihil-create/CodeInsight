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


int main() {
	ll N, Z, W;
	cin >> N >> Z >> W;
	vector<ll> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	ll ans = 0;
	{
		ll z = a[N - 1];
		ans = abs(W - z);
	}
	if(N != 1){
		ll z = a[N - 2];
		ll w = a[N - 1];
		ans = max(ans, abs(w - z));
	}
	cout << ans << endl;
}