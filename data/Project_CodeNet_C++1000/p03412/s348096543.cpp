#include "bits/stdc++.h"
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
int a[200000];
int b[200000];
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = 0; i < N; i++) cin >> b[i];
	int ans = 0;
	for (int k = 0; k < 30; k++) {
		vector<int> odd, even;
		for (int i = 0; i < N; i++) {
			if (a[i] & (1 << k)) odd.push_back(a[i] % (1 << k));
			else even.push_back(a[i] % (1 << k));
		}
		sort(odd.begin(), odd.end());
		sort(even.begin(), even.end());
		LL cnt = 0;
		for (int i = 0; i < N; i++) {
			int c = b[i] % (1 << k);
			if (b[i] & (1 << k)) {
				cnt += lower_bound(even.begin(), even.end(), (1 << k) - c) - even.begin();
				cnt += odd.end() - lower_bound(odd.begin(), odd.end(), (1 << k) - c);
			}
			else {
				cnt += lower_bound(odd.begin(), odd.end(), (1 << k) - c) - odd.begin();
				cnt += even.end() - lower_bound(even.begin(), even.end(), (1 << k) - c);
			}
		}
		if (cnt % 2) ans |= (1 << k);
	}
	cout << ans << endl;
}