#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i < (ll)(n); ++i)
#define MOD 1000000007
typedef long long  ll;

using namespace std;

typedef pair<int, int> P;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	map<int, int> m1, m2;
	m1[-1] = 0;
	m2[-1] = 0;
	rep(i, N) {
		int v;
		cin >> v;
		if (i % 2 == 0) {
			m1[v]++;
		}
		else {
			m2[v]++;
		}
	}

	vector<P> v1, v2;
	for (auto p : m1) {
		v1.push_back(make_pair(p.second, p.first));
	}
	for (auto p : m2) {
		v2.push_back(make_pair(p.second, p.first));
	}

	sort(v1.begin(), v1.end(), greater<P>());
	sort(v2.begin(), v2.end(), greater<P>());

	int v1max = v1[0].first;
	int v2max = v2[0].first;

	if (v1[0].second == v2[0].second) {
		if ((v1[0].first - v1[1].first) < (v2[0].first - v2[1].first)) {
			v1max = v1[1].first;
		}
		else {
			v2max = v2[1].first;
		}
	}

	cout << N - v1max - v2max << endl;

	return 0;
}