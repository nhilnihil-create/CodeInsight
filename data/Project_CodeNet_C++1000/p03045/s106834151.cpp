// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100000;

int ds[N];

int find(int i) {
	return ds[i] < 0 ? i : (ds[i] = find(ds[i]));
}

void join(int i, int j) {
	i = find(i);
	j = find(j);
	if (i == j)
		return;
	if (ds[i] > ds[j])
		ds[i] = j;
	else {
		if (ds[i] == ds[j])
			ds[i]--;
		ds[j] = i;
	}
}

int main() {
	int n, m; cin >> n >> m;
	fill(ds, ds + n, -1);
	while (m--) {
		int i, j, z; cin >> i >> j >> z, i--, j--;
		join(i, j);
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (ds[i] < 0)
			ans++;
	cout << ans << '\n';
	return 0;
}
