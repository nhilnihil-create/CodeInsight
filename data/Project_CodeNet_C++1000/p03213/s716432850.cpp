
// D - 756

// DFS + メモ化による解法

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

const int UNCONF = -1;

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

vector<pair<int, int>> prime_cnt;
int memo[100][100];

int dfs(int i, int cnt) {
	if (cnt > 75) return 0;
	if (memo[i][cnt] != UNCONF) return memo[i][cnt];

	if (i == prime_cnt.size() - 1) {
		if (cnt == 75) {
			memo[i][cnt] = 1;
			return 1;
		} else {
			memo[i][cnt] = 0;
			return 0;
		}
	}

	int result = 0;
	for (int j=0; j<=prime_cnt[i].second; j++) {
		result += dfs(i+1, cnt * (j+1));
	}

	memo[i][cnt] = result;
	return result;
}

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

	for (auto itr : primes) {
		int prime = itr.first;
		int cnt = itr.second;
		//cout << itr.first << " " << itr.second << endl; // **** debug ****
		prime_cnt.push_back(make_pair(prime, cnt));
	}

	for (int i=0; i<100; i++) {
		for (int j=0; j<100; j++) {
			memo[i][j] = UNCONF;
		}
	}

	int ans = dfs(0, 1);

	cout << ans << endl;

	return 0;
}