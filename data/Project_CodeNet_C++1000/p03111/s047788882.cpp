#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int power(int x, int k) {
	int res = 1;
	rep(i, k) res *= x;
	return res;
}

int main() {
	int n, A, B, C;
	cin >> n >> A >> B >> C;
	vector<int> l(n);
	rep (i, n) cin >> l[i];
	int ans = 1001001001;
	int mx = power(3, n);
	for(int bit = 1; bit < mx; bit++) {
		vector<int> a, b, c;
		int tmp = bit;
		rep(i, n) {
			if(tmp%3 == 0) {
				a.push_back(l[i]);
			} else if(tmp%3 == 1) {
				b.push_back(l[i]);
			} else {
				c.push_back(l[i]);
			}
			tmp /= 3;
		}
		int na = a.size();
		int nb = b.size();
		int nc = c.size();
		if(na == 0 || nb == 0 || nc == 0) continue;
		// printf("%d %d %d\n", na, nb, nc);
		// rep(i, na) cout << a[i] << ((i == na-1) ? '\n': ' ');
		// rep(i, nb) cout << b[i] << ((i == nb-1) ? '\n': ' ');
		// rep(i, nc) cout << c[i] << ((i == nc-1) ? '\n': ' ');
		// cout << endl;
		int al = 1001001001;
		for(int bit2 = 1; bit2 < (1 << na); bit2++) {
			int nowl = 0;
			int cnt = 0;
			rep(i, na) {
				if((bit2 >> i) & 1) {
					nowl += a[i];
					cnt++;
				}
			}
			int nowmp = abs(A - nowl);
			nowmp += (cnt-1) * 10;
			al = min(al, nowmp);
		}
		int bl = 1001001001;
		for(int bit2 = 1; bit2 < (1 << nb); bit2++) {
			int nowl = 0;
			int cnt = 0;
			rep(i, nb) {
				if((bit2 >> i) & 1) {
					nowl += b[i];
					cnt++;
				}
			}
			int nowmp = abs(B - nowl);
			nowmp += (cnt-1) * 10;
			bl = min(bl, nowmp);
		}
		int cl = 1001001001;
		for(int bit2 = 1; bit2 < (1 << nc); bit2++) {
			int nowl = 0;
			int cnt = 0;
			rep(i, nc) {
				if((bit2 >> i) & 1) {
					nowl += c[i];
					cnt++;
				}
			}
			int nowmp = abs(C - nowl);
			nowmp += (cnt-1) * 10;
			cl = min(cl, nowmp);
		}
		int now = al + bl + cl;
		ans = min(ans, now);
	}
	printf("%d\n", ans);
	return 0;
}