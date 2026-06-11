#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define myfill(a, val, type) fill((type *)a, (type *)a+sizeof(a)/sizeof(type), val)

int main() {
	long long n, k;
	cin >> n >> k;
	vector<pair<int,int>> sushi(n);
	for (int i = 0; i < n; i++) {
		cin >> sushi[i].second >> sushi[i].first;
		sushi[i].second--;
	}
	sort(sushi.begin(), sushi.end(), greater<pair<int,int>>());
	int neta_t[n]; myfill(neta_t, 0, int);
	long long oishi = 0, neta = 0;
	for (int i = 0; i < k; i++) {
		int d = sushi[i].first, t = sushi[i].second;
		if (neta_t[t] == 0) neta++;
		neta_t[t]++;
		oishi += d;
	}
	long long ans = oishi + neta * neta;
	int a = k-1, b = k;
	auto next_sushi = [&]() {
		bool ok1 = false, ok2 = false;
		while (a >= 0) {
			int d = sushi[a].first, t = sushi[a].second;
			a--;
			if (neta_t[t] == 1) continue;
			neta_t[t]--;
			oishi -= d;
			ok1 = true;
			break;
		}
		while (b < n) {
			int d = sushi[b].first, t = sushi[b].second;
			b++;
			if (neta_t[t] != 0) continue;
			neta_t[t]++;
			neta++;
			oishi += d;
			ok2 = true;
			break;
		}
		return ok1 && ok2;
	};
	while (next_sushi()) {
		long long now = oishi + neta * neta;
		ans = max(ans, now);
	}
	cout << ans << endl;
	return 0;
}