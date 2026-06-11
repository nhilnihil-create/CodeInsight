#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<string, string> P;
const ll MOD = 1000000007LL;
ll sum_r[100001];
int main() {
	int N;
	cin >> N;
	vector<int> vl, vr;
	for (int i = 0; i < N; i++) {
		int L, R;
		cin >> L >> R;
		vl.push_back(L * 2);
		vr.push_back(-R * 2);
	}
	sort(vl.rbegin(), vl.rend());
	sort(vr.rbegin(), vr.rend());
	for (int i = 0; i < N; i++) {
		sum_r[i + 1] = sum_r[i] + vr[i];
	}
	ll ans = 0;
	ll sum_l = 0;
	for (int i = 0; i <= N; i++) {
		for (int j = -1; j <= 1; j++) {
			int k = i + j;
			if (k<0 || k>N) continue;
			ans = max(ans, sum_l + sum_r[k]);
		}
		if (i < N) sum_l += vl[i];
	}
	cout << ans << endl;
}