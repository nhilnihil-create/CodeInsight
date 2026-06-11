#include <iostream>
using namespace std;
long long gcd(long long n, long long m){
	if(n%m==0){
		return m;
	}else{
		return gcd(m, n%m);
	}
}
int main() {
	long long n, k, x, ans = 0;
	cin >> n >> k;
	cin >> x;
	ans = abs(x-k);
	for (int i=0; i<n-1; i++) {
		cin >> x;
		long long temp = abs(x-k);
		ans = gcd(ans, temp);
	}
	cout << ans << endl;
}