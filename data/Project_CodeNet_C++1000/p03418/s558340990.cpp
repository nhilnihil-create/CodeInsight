#include <bits/stdc++.h>
using namespace std;

int main(void){
	long long n, k;
	cin >> n >> k;
	long long ans = 0;
	for(int i = k+1; i <= n; ++i){
		ans += n - (k!=0?((n/i)*k-1):0) - min(n-n/i*i+1, k);
	}
	cout << ans << endl;
	return 0;
}