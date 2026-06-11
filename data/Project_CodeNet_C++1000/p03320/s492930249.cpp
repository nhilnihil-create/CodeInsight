#include <bits/stdc++.h>
using namespace std;

double calc(long long x){
	long long sum = 0, rec = x;
	while (rec){
		sum += rec % 10;
		rec /= 10;
	}
	return 1.0 * x / sum;
}

int main(){
	int k;
	long long ans, x;
	cin >> k;
	ans = 0; x = 1;
	for (int i = 1; i <= k; i++){
		while (true){
			if (calc(ans + x) <= calc(ans + x * 10)) break;
			x *= 10;
		}
		ans += x;
		cout << ans << '\n';
	}
	return 0;
}