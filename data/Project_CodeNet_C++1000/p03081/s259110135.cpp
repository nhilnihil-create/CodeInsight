#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 100;

char t[N], d[N];
string s;
int n, q, ans;

bool check1(int m) {
	for (int i = 0; i < q; i++) {
		if (s[m] == t[i]) {
			if (d[i] == 'R')
				m++;
			else
				m--;
			if (m == n)
				return true;
		}
	}
	return false;
}

bool check2(int m) {
	for (int i = 0; i < q; i++) {
		if (s[m] == t[i]) {
			if (d[i] == 'R')
				m++;
			else
				m--;
			if (m < 0)
				return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> q >> s;
	for (int i = 0; i < q; i++)
		cin >> t[i] >> d[i];
	int s = -1, e = n;
	while (e - s > 1) {
		int m = (s + e) / 2;
		if (check1(m))
			e = m;
		else
			s = m;
	}
	ans = e - 1;
	s = 0, e = n + 1;
	while (e - s > 1) {
		int m = (s + e) / 2;
		if (check2(m))
			s = m;
		else
			e = m;	
	}
	ans -= s;
	return cout << (ans >= 0 ? ans : 0), 0;
}