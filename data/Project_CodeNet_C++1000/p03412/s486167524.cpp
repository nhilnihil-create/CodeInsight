#include <bits/stdc++.h>
using namespace std;

long long a[200010], b[200010];

int main(){
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
	}
	for (int i = 0; i < n; i++){
		scanf("%lld", &b[i]);
	}
	int ans = 0;
	for (int k = 0; k < 29; k++){
		vector <int> v;
		for (int i = 0; i < n; i++){
			v.push_back(b[i] & ((1 << k + 1) - 1));
		}
		sort(v.begin(), v.end());
		long long tot = 0;
		for (int i = 0; i < n; i++){
			int x = a[i] & ((1 << k + 1) - 1);
			int pos1 = lower_bound(v.begin(), v.end(), (1 << k) - x) - v.begin();
			int pos2 = lower_bound(v.begin(), v.end(), 2 * (1 << k) - x) - v.begin();
			int pos3 = lower_bound(v.begin(), v.end(), 3 * (1 << k) - x) - v.begin();
			int pos4 = lower_bound(v.begin(), v.end(), 4 * (1 << k) - x) - v.begin();
			tot += pos2 - pos1 + pos4 - pos3;
		}
		if (tot & 1) ans += 1 << k;
	}
	printf("%d\n", ans);
	return 0;
}
