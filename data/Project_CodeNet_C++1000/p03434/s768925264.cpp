#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 110;
int n, a[N];

int main() {
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+1+n);
	
	int ans = 0;
	for(int i = n; i >= 1; i -= 2) {
		ans += a[i] - a[i-1];
	}
	cout << ans << endl;
	return 0;
} 