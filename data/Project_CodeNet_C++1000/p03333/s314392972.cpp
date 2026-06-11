#include <bits/stdc++.h>

using namespace std;

int n;
multiset< pair<long long, long long> > sl, sr, tl, tr;

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	while (n--) {
		long long l, r; 
		cin >> l >> r;
		sl.insert({l, r});
		sr.insert({r, l});
	}
	long long cur, res, mx;
	mx = 0;
	{
		cur = res = 0;
		tl = sl, tr = sr;
		while (tl.size()) {
			auto ir = tr.begin();
			auto il = --(tl.end());
			if (ir -> first < cur) {
				res += cur - ir -> first, cur = ir -> first;
				tl.erase(tl.find({ir -> second, ir -> first}));
				tr.erase(ir);
				continue;
			}
			if (il -> first > cur) {
				res += il -> first - cur, cur = il -> first;
				tr.erase(tr.find({il -> second, il -> first}));
				tl.erase(il);
				continue;
			}
			break;
		}
		res += abs(cur);
	}
	mx = max(mx, res);
	{
		cur = res = 0;
		tl = sl, tr = sr;
		while (tl.size()) {
			auto ir = tr.begin();
			auto il = --(tl.end());
			if (il -> first > cur) {
				res += il -> first - cur, cur = il -> first;
				tr.erase(tr.find({il -> second, il -> first}));
				tl.erase(il);
				continue;
			}
			if (ir -> first < cur) {
				res += cur - ir -> first, cur = ir -> first;
				tl.erase(tl.find({ir -> second, ir -> first}));
				tr.erase(ir);
				continue;
			}
			break;
		}
		res += abs(cur);
	}
	mx = max(mx, res);
	cout << mx;
}