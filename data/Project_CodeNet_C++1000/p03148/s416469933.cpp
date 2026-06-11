// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100000;

int tt[N], dd[N], ii[N], jj[N];
long long pp[N + 1], qq[N + 1];

int main() {
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> tt[i] >> dd[i];
		ii[i] = i;
	}
	sort(ii, ii + n, [] (int i, int j) { return tt[i] < tt[j] || tt[i] == tt[j] && dd[i] > dd[j]; });
	int n_ = 0, m = 0;
	for (int i = 0; i < n; i++)
		if (i == 0 || tt[ii[i - 1]] != tt[ii[i]])
			jj[m++] = ii[i];
		else
			ii[n_++] = ii[i];
	n = n_;
	sort(ii, ii + n, [] (int i, int j) { return dd[i] > dd[j]; });
	sort(jj, jj + m, [] (int i, int j) { return dd[i] > dd[j]; });
	for (int i = 0; i < n; i++)
		pp[i + 1] = pp[i] + dd[ii[i]];
	for (int j = 0; j < m; j++)
		qq[j + 1] = qq[j] + dd[jj[j]];
	long long ans = 0;
	for (int x = max(k - n, 1); x <= k && x <= m; x++)
		ans = max(ans, qq[x] + pp[k - x] + (long long) x * x);
	cout << ans << '\n';
	return 0;
}
