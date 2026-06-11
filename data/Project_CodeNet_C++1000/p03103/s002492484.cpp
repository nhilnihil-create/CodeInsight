#include<bits/stdc++.h>
using namespace std;

int main() {
	long long n, m; cin >> n >> m;
	pair<long long, long long> d[n];
	for (int i = 0; i < n; i++)
	{
		cin >> d[i].first >> d[i].second;
	}
	sort(d, d + n);

	long long res = 0, id = 0;
	while (m > 0)
	{
		res += d[id].first * min(m, d[id].second);
		m -= min(m, d[id].second);
		id++;
	}
	cout << res << endl;
	return 0;
}
