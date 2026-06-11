#include <bits/stdc++.h> 

using namespace std;

const int N = (int)1e5 + 7;

int a[N];

main() {    
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	cout << a[n] << ' ';
	int mid = (a[n] + 1) / 2;
	int dif = 1e9;
	int ans;
	for (int i = 1; i < n; i++) {
		if (abs(a[i] - mid) < dif) {
			ans = a[i];
			dif = abs(a[i] - mid);
		}
	}	
	cout << ans;
}