#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<ll>> a(N, vector<ll>(3));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) cin >> a[i][j];
	}
	ll ans = -1e14;
	for(int i=0;i<8;i++) {
		vector<ll> vec;
		for(int j=0;j<N;j++) {
			ll tmp = 0;
			for(int k=0;k<3;k++) {
				tmp += ((i & (1 << k)) ? a[j][k] : (-1LL) * a[j][k]);
			}
			vec.push_back(tmp);
		}
		sort(vec.rbegin(), vec.rend());
		ll tmp_ans = 0;
		for(int j=0;j<M;j++) tmp_ans += vec[j];
		ans = max(ans, tmp_ans);
	}
	cout << ans << endl;
}