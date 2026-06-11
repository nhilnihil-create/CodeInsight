#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, m, ans = 1;
	cin >> n >> m;
	for(long long i = 1; i * i <= m; ++i){
		if(m%i) continue;
		long long f = m/i;
		if(n*f <= m) ans = max(ans, f);
		if(n*i <= m) ans = max(ans, i);
	}
	cout << ans;
	
	return 0;
}