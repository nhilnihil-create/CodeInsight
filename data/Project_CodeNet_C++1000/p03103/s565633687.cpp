#include<bits/stdc++.h>
using namespace std;

int main() {
	long long n, m; cin >> n >> m;
	vector<pair<long long, long long>> d(n);
	for (int i = 0; i < n; i++)
	{
		long long a, b;
		cin >> a >> b;
		d[i] = make_pair(a, b);
	}
	sort(d.begin(), d.end());

	long long res = 0;
	int i = 0;
	while (m > 0)
	{
		long long buy = min(m, d[i].second);
		res += d[i].first * buy;
		m -= buy;
		i++;
	}
	cout << res << endl;
	return 0;
}

