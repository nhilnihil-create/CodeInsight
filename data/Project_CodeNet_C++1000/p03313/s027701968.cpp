#include <bits/stdc++.h>
using namespace std;

int b[1 << 21], *a;
int Max[1 << 20], __Max[1 << 20], ans[1 << 20];

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	a = b + 10;
	int n; cin >> n;
	for (int i = 0; i < (1 << n); i++) cin >> a[i];
	for (int s = 0; s < (1 << n); s++) {
		Max[s] = s, __Max[s] = -1;
		for (int i = 0; i < n; i++) if (s >> i & 1) {
			auto t = s ^ (1 << i);
			if (a[Max[s]] == a[Max[t]]) {
				if (Max[s] == Max[t]) {
					if (a[__Max[s]] < a[__Max[t]]) __Max[s] = __Max[t];
				} else __Max[s] = Max[t];
			}
			if (a[Max[s]] > a[Max[t]]) {
				if (a[__Max[s]] < a[Max[t]]) __Max[s] = Max[t];
			}
			if (a[Max[s]] < a[Max[t]]) {
				if (a[Max[s]] < a[__Max[t]]) __Max[s] = __Max[t];
				else __Max[s] = Max[s];
				Max[s] = Max[t];
			}
		}
	}
	for (int s = 0; s < (1 << n); s++) {
		if (s == 0) ans[s] = a[Max[s]];
		else ans[s] = max(a[Max[s]] + a[__Max[s]], ans[s - 1]);
	}
	for (int s = 1; s < (1 << n); s++) cout << ans[s] << "\n";
	
	return 0;
}
