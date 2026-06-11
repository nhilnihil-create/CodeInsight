#include <bits/stdc++.h>

#define int long long

using namespace std;

int a[200001];
vector <int> used[200001];
int n, x, ans = 1e18;
int inf = 1e18;

int calc (int k) {      	
	if (k > n) return inf;
	int cur = k * x + n * x;
    for (int i = 0;i < k;i ++) used[i].clear ();
	for (int i = n;i >= 1;i --) {
		used[i % k].push_back (a[i]);
	}
	for (int i = 0;i < k;i ++) sort (used[i].begin (), used[i].end ());
	for (int i = 0;i < k;i ++) {
		int len = used[i].size () - 1;
		cur += used[i][len];
		int id = 1;
		for (int j = used[i].size () - 1;j > 0;j --) {
			cur += (id + 1) * (id + 1) * (used[i][j] - used[i][j - 1]);
			id ++;
		}
		cur += (id + 1) * (id + 1) * used[i][0];
	}
	return cur;
}
											
 main () {
 	cin >> n;
 	cin >> x;
 	for (int i = 1;i <= n;i ++) {
 		cin >> a[i];
 	}
 	int l = 1, r = n;
 	while (l <= r) {
		int k = (l + r) / 2;
		if (calc (k) <= calc (k + 1)) {
			ans = min (ans, calc (k));
			r = k - 1;
		}
		else {
		    ans = min (ans, calc (k + 1));
			l = k + 1;
 		}
 	}
 	cout << ans;
	return 0; 
}