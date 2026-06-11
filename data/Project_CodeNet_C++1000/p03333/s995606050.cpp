#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int l[N], r[N];
vector<pair<int, int> > ll, rr;
long long ans, rtr, rn;
int mark[N];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> l[i] >> r[i], ll.push_back({-l[i], i}), rr.push_back({r[i], i});
	sort(ll.begin(), ll.end());
	sort(rr.begin(), rr.end());
	if (-ll[0].first > 0) {
		int plcl = 0, plcr = 0;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				while (plcl < n && mark[ll[plcl].second])
					plcl++;
				if (plcl == n)
					break;
				pair<int, int> p = ll[plcl];
				p.first = -p.first;
				if (p.first <= rn)
					break;
				else {
					rtr += p.first - rn;
					rn = p.first;
					mark[p.second] = 1;
				}
			}
			else {
				while (plcr < n && mark[rr[plcr].second])
					plcr++;
				if (plcr == n)
					break;
				pair<int, int> p = rr[plcr];
				if (p.first >= rn)
					break;
				else {
					rtr += rn - p.first;
					rn = p.first;
					mark[p.second] = 1;
				}
			}
		}
		rtr += abs(rn);
	}
	ans = rtr;
	memset(mark, 0, sizeof(mark));
	rtr = rn = 0;
	if (rr[0].first < 0) {	
		int plcl = 0, plcr = 0;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 1) {
				while (plcl < n && mark[ll[plcl].second])
					plcl++;
				if (plcl == n)
					break;
				pair<int, int> p = ll[plcl];
				p.first = -p.first;
				if (p.first <= rn)
					break;
				else {
					rtr += p.first - rn;
					rn = p.first;
					mark[p.second] = 1;
				}
			}
			else {
				while (plcr < n && mark[rr[plcr].second])
					plcr++;
				if (plcr == n)
					break;
				pair<int, int> p = rr[plcr];
				if (p.first >= rn)
					break;
				else {
					rtr += rn - p.first;
					rn = p.first;
					mark[p.second] = 1;
				}
			}
		}
		rtr += abs(rn);
	}
	cout << max(ans, rtr);
	return 0;
}
