#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 100;

int n, q;
char t[N], d[N];
string s;

int get(int dex) {
	for (int i = 0; i < q; i++)
		if(t[i] == s[dex]) {
			if(d[i] == 'L')
				dex--;
			else
				dex++;
			if(dex < 0)
				return -1;
			if(dex >= n)
				return 1;
		}
	return 0;
}

int get_l() {
	int l = -1, r = n;
	while(r - l > 1) {
		int c = (l + r) >> 1;
		if(get(c) == -1)
			l = c;
		else
			r = c;
	}
	return l;
}

int get_r() {
	int l = -1, r = n;
	while(r - l > 1) {
		int c = (l + r) >> 1;
		if(get(c) == 1)
			r = c;
		else
			l = c;
	}
	return r;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> q >> s;
	for (int i = 0; i < q; i++)
		cin >> t[i] >> d[i];
	cout << n - (get_l() + 1 + n - get_r());
	return 0;
}