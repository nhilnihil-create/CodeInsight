//IOI 2021

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;

int n, q, L, R;
string s;
vector<pcc> qu;

int bs1() {
	int t = 0;
	bool f = false;
	for (auto i : qu) {
		if (i.ff == s[t]) {
			if (i.ss == 'L')
				t--;
			else
				t++;
		}
		if (t == -1) {
			f = true;
			break;
		}
		if (t == n)
			break;
	}
	if (!f)
		return 0;

	int l = 0, r = n;
	while (l + 1 < r) {
		int mid = (l + r) / 2;
		int tmp = mid;
		bool flag = false;
		for (auto i : qu) {
			if (i.ff == s[tmp]) {
				if (i.ss == 'L')
					tmp--;
				else
					tmp++;
			}
			if (tmp == -1) {
				flag = true;
				break;
			}
			if (tmp == n)
				break;
		}
		if (flag)
			l = mid;
		else
			r = mid;
	}
	return r;
}

int bs2() {
	int t = n - 1;
	bool f = false;
	for (auto i : qu) {
		if (i.ff == s[t]) {
			if (i.ss == 'L')
				t--;
			else
				t++;
		}
		if (t == -1)
			break;
		if (t == n) {
			f = true;
			break;
		}
	}
	if (!f)
		return n - 1;

	int l = -1, r = n - 1;
	while (l + 1 < r) {
		//cerr << "# " << l << " " << r << endl;
		int mid = (l + r) / 2;
		int tmp = mid;
		bool flag = false;
		for (auto i : qu) {
			if (i.ff == s[tmp]) {
				if (i.ss == 'L')
					tmp--;
				else
					tmp++;
			}
			if (tmp == -1)
				break;
			if (tmp == n) {
				flag = true;
				break;
			}
		}
		cerr << "! " << flag << endl;
		if (flag)
			r = mid;
		else
			l = mid;
	}
	return l;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> q >> s;
	while (q--) {
		char t1, t2;
		cin >> t1 >> t2;
		qu.pb({t1, t2});
	}

	L = bs1();
	R = bs2();
	cerr << L << " " << R << endl;
	cout << R - L + 1 << endl;
	return 0;
}
