#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i <= (ll)(n); ++i)
#define MAX 500010
#define MOD 1000000007
typedef long long  ll;

using namespace std;

ll ans;


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N, M;
	cin >> N >> M;
	vector<vector<ll>> m(N+1);
	vector<ll> P(M), Y(M);
	rep(i, M) {
		cin >> P[i] >> Y[i];
		m[P[i]].push_back(Y[i]);
	}
	
	map<ll, ll> juni;
	repk(i, 1, N) {
		sort(m[i].begin(), m[i].end());
		rep(j, m[i].size()) {
			juni[m[i][j]] = j + 1;
		}
	}

	rep(i, M) {
		printf("%06lld%06lld\n", P[i], juni[Y[i]]);
	}

	return 0;
}
