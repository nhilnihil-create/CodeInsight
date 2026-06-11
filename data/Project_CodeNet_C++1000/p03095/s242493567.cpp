#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

const ll MOD = 1000000007;

int main() {
	ll N;
	cin >> N;
	string S;
	cin >> S;

	map<char, ll> m;
	for (int ii = 0; ii < N; ++ii){
		m[S[ii]] += 1;
	}

	ll ans = 1;
	for (char c = 'a'; c <= 'z'; ++c){
		ans = (ans * (m[c] + 1)) % MOD;
	}

	cout << ans - 1 << endl;

	return 0;
}
