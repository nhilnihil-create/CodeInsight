
// D - Five, Five Everywhere

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

// n以下の素数をエラトステネスの篩で求めてvectorで返す
vector<int> sieve(int n) {
	vector<int> prime;
	prime.reserve(n);

	vector<bool> is_prime(n+1, true);

	is_prime[0] = is_prime[1] = false;

	for (int i=2; i<=n; i++) {
		if (is_prime[i]) {
			prime.push_back(i);
			for (int j=2*i; j<=n; j+=i) {
				is_prime[j] = false;
			}
		}
	}

	return prime;
}


int main() {
	int N;
	cin >> N;

	vector<int> S = sieve(55555);
	vector<int> ans;

	for (int s : S) {
		if (s % 5 == 1) ans.push_back(s);
	}

	for (int i=0; i<N; i++) {
		if (i != 0) cout << " ";
		cout << ans[i];
	}
	cout << endl;

	return 0;
}