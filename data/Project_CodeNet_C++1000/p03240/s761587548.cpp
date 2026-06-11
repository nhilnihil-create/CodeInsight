#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	vector<tuple<long long, long long, long long>> d;
	vector<tuple<long long, long long>> z;
	for (int i = 0; i < n; i++) {
		long long x, y, h;
		cin >> x >> y >> h;
		if (h == 0)
			z.push_back(make_tuple(x, y));
		else
			d.push_back(make_tuple(x, y, h));
	}
	for (long long cx = 0; cx <= 100; cx++) {
		for (long long cy = 0; cy <= 100; cy++) {
			bool ok = true;
			long long H = get<2>(d[0]) + abs(get<0>(d[0]) - cx) + abs(get<1>(d[0]) - cy);
			for (int i = 1; i < d.size(); i++) {
				long long tH = get<2>(d[i]) + abs(get<0>(d[i]) - cx) + abs(get<1>(d[i]) - cy);
				if (H != tH) {
					ok = false;
					break;
				}
			}
			if (!ok)
				continue;
			for (int i = 0; i < z.size(); i++) {
				if ((H - abs(get<0>(z[i])-cx) - abs(get<1>(z[i])-cy)) > 0) {
					ok = false;
					break;
				}
			}
			if (ok) {
				printf("%lld %lld %lld\n", cx, cy, H);
				return 0;
			}
		}
	}
	return 0;
}