#include <bits/stdc++.h>

#define N 200010 

using namespace std;

typedef long long ll;

char *p1, *p2, buf[100000];

#define nc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1 ++ )

int rd() {
	int x = 0, f = 1;
	char c = nc();
	while (c < 48) {
		if (c == '-')
			f = -1;
		c = nc();
	}
	while (c > 47) {
		x = (((x << 2) + x) << 1) + (c ^ 48), c = nc();
	}
	return x * f;
}

int a[N], n;

map <ll, ll> MP;

bool check(int x) {
	MP.clear();
	for (int i = 2; i <= n; i ++ ) {
		if (a[i - 1] >= a[i]) {
			if (x == 1) {
				return false;
			}
			while (!MP.empty()) {
				ll mx = MP.rbegin() -> first;
				if (mx > a[i]) {
					MP.erase(mx);
				}
				else {
					break;
				}
			}

			int j = a[i];
			while (j > 0 && MP[j] + 1 == x) {
				MP.erase(j);
				j -- ;
			}
			if (!j) {
				return false;
			}
			MP[j] ++ ;
		}
	}
	return true;
}


int main() {
	n = rd();
	for (int i = 1; i <= n; i ++ ) {
		a[i] = rd();
	}

	int l = 1, r = n, ans = n;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << ans << endl ;
	return 0;
}