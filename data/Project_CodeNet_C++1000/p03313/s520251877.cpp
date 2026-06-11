#include <bits/stdc++.h>
using namespace std;

const int N = 18;
int n, a[1 << N], b[1 << N];

inline void check(int x, int y) {
	if(a[y] > a[x]) b[x] = max(a[x], b[y]), a[x] = a[y];
	else if(a[y] > b[x]) b[x] = a[y]; 
} 

int main() {
	cin >> n;
	for(int i = 0; i < 1 << n; ++i) cin >> a[i];
	for(int k = 0; k < n; ++k)
		for(int i = 0; i < 1 << n; ++i)	
			if(i >> k & 1) check(i, i ^ (1 << k));
	for(int i = 0, ans = 0; i < 1 << n; ++i) {
		ans = max(ans, a[i] + b[i]);
		if(i) printf("%d\n", ans);
	}
	return 0;
} 