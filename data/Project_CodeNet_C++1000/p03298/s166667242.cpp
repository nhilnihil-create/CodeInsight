#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
char s[100];
ll ans;
map<pair<unsigned int, unsigned int>, int> M;
int main() {
	cin >> n;
	cin >> s;
	for (int i = 0; i < (1 << n); ++i) {
		unsigned int t1 = 0, t2 = 0;
		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				t1 *= 13131;
				t1 += s[j];
			} else {
				t2 *= 13131;
				t2 += s[j];
			}
		}
		M[make_pair(t1, t2)]++;
	}
	reverse(s, s + 2 * n);
	for (int i = 0; i < (1 << n); ++i) {
		unsigned int t1 = 0, t2 = 0;
		for (int j = 0; j < n; j++) {
			if ((i >> j) & 1) {
				t1 *= 13131;
				t1 += s[j];
			} else {
				t2 *= 13131;
				t2 += s[j];
			}
		}
		ans += M[make_pair(t2, t1)];
	}
	cout << ans;
}