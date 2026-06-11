#include <bits/stdc++.h>
using namespace std;

int n;
long long x[1005], y[1005];
string s[1005];
long long d[40];
int tot = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i] >> y[i];
	}
	if ((x[1] & 1) == (y[1] & 1)) {
		d[++tot] = 1;
		for (int i = 1; i <= n; ++i) {
			s[i] += 'U';
			y[i]--;
		}
	}
	long long len = 1;
	while (len < (1LL << 33)) {
		d[++tot] = len;
		for (int i = 1; i <= n; ++i) {
			if ((x[i] & 1) == (y[i] & 1)) {
				return cout << -1 << '\n',0;
			}
			if (x[i] & 1) {
				if (((x[i] - 1) & 2) != (y[i] & 2)) {
					x[i]--;
					s[i] += 'R';
				}
				else {
					x[i]++;
					s[i] += 'L';
				}
			}
			else {
				if (((y[i] - 1) & 2) != (x[i] & 2)) {
					y[i]--;
					s[i] += 'U';
				} 
				else {
					y[i]++;
					s[i] += 'D';
				}
			}
			x[i] >>= 1;
			y[i] >>= 1;
		}
		len <<= 1;
	}
	d[++tot] = len;
	for (int i = 1; i <= n; ++i) {
		s[i] += (x[i] == 1 ? 'R' : (x[i] == -1 ? 'L' : (y[i] == 1 ? 'U' : 'D')));
	}
	cout << tot << '\n';
	for (int i = 1; i <= tot; ++i) cout << d[i] << ' '; 
	cout << '\n';
	for (int i = 1; i <= n; ++i) cout << s[i] << '\n';
}
