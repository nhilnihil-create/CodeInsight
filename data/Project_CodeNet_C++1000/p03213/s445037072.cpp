
// D - 756

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

vector<pair<ll, ll>> prime_factorize(ll n) {
	vector<pair<ll, ll> > result;
	for (ll p=2; p*p<=n; p++) {
		if (n % p != 0) continue;
		ll num = 0;
		while (n % p == 0) {
			num++;
			n /= p;
		}
		result.push_back(make_pair(p, num));
    }
    if (n != 1) {
    	result.push_back(make_pair(n, 1));
    }
    return result;
}

int dp[100][76]; // dp[i][s]: i個目までを用いて約数の個数をsにできる組み合わせの数

int main() {
	int N;
	cin >> N;

	if (N == 1) {
		cout << 0 << endl;
		return 0;
	}

	map<int, int> primes;

	for (int i=2; i<=N; i++) {
		vector<pair<ll, ll>> pf = prime_factorize(i);

		for (auto p: pf) {
			primes[p.first] += p.second;
		}
	}

	vector<pair<int, int>> prime_cnt;
	for (auto itr : primes) {
		int prime = itr.first;
		int cnt = itr.second;
		//cout << itr.first << " " << itr.second << endl; // **** debug ****
		prime_cnt.push_back(make_pair(prime, cnt));
	}

	dp[0][1] = true;
	for (int i=0; i<prime_cnt.size(); i++) {
		int cnt = prime_cnt[i].second;

		// i+1個目の素数を加えない
		for (int s=1; s<=75; s++) {
			dp[i+1][s] = dp[i][s];
		}

		// i+1個目の素数を1つ以上用いる
		for (int s=1; s<=75; s++) {
			for (int x=1; x<=cnt; x++) {
				if (s * (x+1) <= 75) dp[i+1][s * (x+1)] += dp[i][s];
			}
		}
	}

	int ans = dp[prime_cnt.size()][75];

	// **** debug ****
	/*
	for (int i=0; i<prime_cnt.size(); i++) {
		cout << "i=" << i << endl;
		for (int s=1; s<=75; s++) {
			cout << " " << dp[i][s];
		}
		cout << endl;
	}
	*/

	cout << ans << endl;

	return 0;
}