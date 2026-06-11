
// A - Zero-Sum Ranges

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

ll A[200000];
ll S[200001];

ll comb2(ll n) {
	return n * (n-1) / 2;
}

int main() {
	int N;
	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> A[i];
	}

	for (int i=0; i<N; i++) {
		S[i+1] = S[i] + A[i];
	}

	unordered_map<ll, ll> cnt;
	for (int i=0; i<=N; i++) {
		cnt[S[i]]++;
	}

	ll ans = 0;
	for (auto itr : cnt) {
		ll val = itr.second;
		ans += comb2(val);
	}

	cout << ans << endl;

	return 0;
}