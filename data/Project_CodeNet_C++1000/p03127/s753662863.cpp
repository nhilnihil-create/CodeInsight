#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n;

lli gcd(lli a, lli b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(void){
	cin >> n;
	lli ans = 0;
	rep(i, n){
		lli a;
		cin >> a;
		ans = gcd(ans, a);
	}
	cout << ans << endl;
	return 0;
}
