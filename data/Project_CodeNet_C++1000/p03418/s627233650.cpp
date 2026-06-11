#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll inf = 1LL<<60;
const double eps = 1e-9;

typedef pair<ll, ll> P;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main()
{
	ll N, K;
	cin >> N >> K;
	ll res = 0;
	for (ll i = 1; i <= N; i++) {
		ll p = N / i;
		ll r = N % i;
		ll temp = max(0LL, i - K);
		res += p * temp;
		res += max(0LL, r - K + 1);
	}
    
	if (K == 0) {
		res -= N;
	}

	cout << res << endl;
	return 0;
}
