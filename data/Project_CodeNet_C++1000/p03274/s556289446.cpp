#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	int n, k; cin >> n >> k;
	vector<ll> X;
	for (int i=0; i<n; i++) {
		ll x; cin >> x;
		X.push_back(x);
	}
	ll mint = INF;
	for (int i=0; i + k - 1 < n; i++) {
		ll now;
		int j = i + k -1;
		if (X[j] <= 0) now = - X[i];
		else if (X[i] >= 0) now = X[j];
		else if (abs(X[i]) >= X[j]) now = 2 * X[j] - X[i];
		else now = - 2 * X[i] + X[j];
		
		if (now < mint) mint = now;
	}
	cout << mint << endl;
	return 0;
}