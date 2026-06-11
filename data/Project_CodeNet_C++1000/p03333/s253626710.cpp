#include <iostream>
#include <stdio.h>
#include <string>
#include <memory.h>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <time.h>
#include <assert.h>
#include <cmath>
#include <stack>
#include <string.h>
#include <sstream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	scanf("%d", &n);
	vector<pair<int, int> > w;
	for (int i = 0; i < n; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		w.push_back({ l,r });
	}
	ll res = 1e18;
	for (int it = 0; it < 1; ++it) {
		ll kk = 0;
		for (int jt = 0; jt < 2; ++jt) {
			ll k = 0;
			ll cur = 0;
			multiset<pair<int, int> > mn, mx;
			for (int i = 0; i < n; ++i) {
				int l = w[i].first;
				int r = w[i].second;
				if (it == 1) {
					l = -l;
					r = -r;
					swap(l, r);
				}
				mx.insert(make_pair(l, r));
				mn.insert(make_pair(r, l));
			}
			for (int i = 0; i < n; ++i) {
				if (((i % 2) ^ jt) == 0) {
					auto u = *--mx.end();
					mx.erase(--mx.end());
					int l = u.first;
					int r = u.second;
					mn.erase(mn.find(make_pair(r, l)));
					if (cur > r) {
						k += cur - r;
						cur = r;
					}
					else if (l > cur) {
						k += l - cur;
						cur = l;
					}
				}
				else {
					auto u = *mn.begin();
					mn.erase(mn.begin());
					int l = u.second;
					int r = u.first;
					mx.erase(mx.find(make_pair(l, r)));
					if (cur > r) {
						k += cur - r;
						cur = r;
					}
					else if (l > cur) {
						k += l - cur;
						cur = l;
					}
				}
			}
			k += abs(cur);
			kk = max(kk, k);
		}
		res = min(res, kk);
	}
	cout << res << endl;
	return 0;
}