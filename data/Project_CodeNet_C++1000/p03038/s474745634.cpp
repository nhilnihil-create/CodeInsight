#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n, m;
	cin >> n >>m;
	map<long long, int> ma;
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		ma[a]++;
	}
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
	for (auto e : ma) {
		q.push(make_pair(e.first, e.second));
	}
	for (int i = 0; i < m; i++) {
		int b;
		long long c;
		cin >> b >> c;
		int s = q.size();
		vector<pair<long long, int>> todo;
		long long csum = 0;
		long long porig, porigsum = 0;
		for (int j = 0; j < s; j++) {
			auto p = q.top();
			if (p.first > c)
				break;
			q.pop();

			if (p.second <= b) {
				csum += p.second;
				b -= p.second;
				if (b == 0)
					break;
			} else {
				porig = p.first;
				porigsum = p.second-b;
				csum += b;
				//auto newp0 = make_pair(p.first, p.second-b);
				//auto newp1 = make_pair(c, b);
				break;
			}
		}
		if (csum != 0)
			q.push(make_pair(c, csum));
		if (porigsum != 0)
			q.push(make_pair(porig, porigsum));
	}

	long long ans = 0;
	while (!q.empty()) {
		auto p = q.top();
		ans += p.first * p.second;
		q.pop();
	}

	cout << ans << endl;

	return 0;
}