#include <bits/stdc++.h>

#define N 200010 

using namespace std;

typedef long long ll;


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
	scanf("%d",&n);
	for (int i = 1; i <= n; i ++ ) {
		scanf("%d",&a[i]);
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