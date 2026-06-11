#include<bits/stdc++.h>
using namespace std;
//typedef __int128 lll;
typedef long long ll;
int main() {
	ll n,k;
	cin >> n >> k;
	if(k == 0) {
		cout << n*n;
		return 0;
	}//printf("%lld",n*n);
	ll ans = 0;
	// b > k
	for(int i = k + 1;i <= n ;i++)
	{
		ans += (n/i) * (i - k);
		if(n%i >= k) ans += n%i - k + 1; 
	}
	printf("%lld",ans);
}