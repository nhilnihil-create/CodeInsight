#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int a, b, q;
	cin >> a >> b >> q;
	vector<long long> s(a);
	vector<long long> t(b);
	for (int i = 0; i < a; i++)
		cin >> s[i];
	for (int i = 0; i < b; i++)
		cin >> t[i];
	for (int i = 0; i < q; i++) {
		long long x;
		cin >> x;
		auto sit = lower_bound(s.begin(), s.end(), x);
		auto tit = lower_bound(t.begin(), t.end(), x);
		long long lefts = -1, rights = -1;
		long long leftt = -1, rightt = -1;
		if (sit != s.end()) {
			if (*sit == x) {
				lefts = x;
				rights = x;
			}
		}
		if (lefts == -1 && rights == -1) {
			if (sit == s.end()) {
				lefts = *(s.end()-1);
			} else if (sit == s.begin()) {
				rights = *(s.begin());
			} else {
				lefts = *(sit-1);
				rights = *(sit);
			}
		}

		if (tit != t.end()) {
			if (*tit == x) {
				leftt = x;
				rightt = x;
			}
		}
		if (leftt == -1 && rightt == -1) {
			if (tit == t.end()) {
				leftt = *(t.end()-1);
			} else if (tit == t.begin()) {
				rightt = *(t.begin());
				if (*tit == x) {
					leftt = x;
				}
			} else {
				leftt = *(tit-1);
				rightt = *(tit);
			}
		}
		long long ans = (long long)1e15;
		if (lefts == -1) {
			if (leftt == -1) {
				ans = min(ans, (max(rights, rightt)-x));
			} else if (rightt == -1) {
				ans = min(ans, ((rights-leftt)+(x-leftt)));
				ans = min(ans, ((rights-leftt)+(rights-x)));
			} else {
				ans = min(ans, ((rights-leftt)+(x-leftt)));
				ans = min(ans, ((rights-leftt)+(rights-x)));
				ans = min(ans, (max(rights, rightt)-x));
			}
		} else if (rights == -1) {
			if (rightt == -1) {
				ans = min(ans, x-min(lefts, leftt));
			} else if (leftt == -1) {
				ans = min(ans, (rightt-lefts)+(x-lefts));
				ans = min(ans, (rightt-lefts)+(rightt-x));
			} else {
				ans = min(ans, (rightt-lefts)+(x-lefts));
				ans = min(ans, (rightt-lefts)+(rightt-x));
				ans = min(ans, x-min(lefts, leftt));
			}
		} else {
			if (leftt == -1) {
				ans = min(ans, max(rights, rightt)-x);
				ans = min(ans, rightt-lefts + (x-lefts));
				ans = min(ans, rightt-lefts + (rightt-x));
			} else if (rightt == -1) {
				ans = min(ans, x-min(lefts, leftt));
				ans = min(ans, rights-leftt + (x-leftt));
				ans = min(ans, rights-leftt + (rights-x));
			} else {
				ans = min(ans, max(rights, rightt)-x);
				ans = min(ans, x-min(lefts, leftt));
				ans = min(ans, rights-leftt + (x-leftt));
				ans = min(ans, rights-leftt + (rights-x));
				ans = min(ans, rightt-lefts + (x-lefts));
				ans = min(ans, rightt-lefts + (rightt-x));
			}
		}
		cout << ans << endl;
	}

	return 0;
}