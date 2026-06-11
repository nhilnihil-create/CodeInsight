#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n, xs;

lli gcd(lli a, lli b){
	if(b == 0) return a;
	else return gcd(b, a%b);
}

int main(void){
	cin >> n >> xs;
	lli ans = 0;
	rep(i, n){
		lli x;
		cin >> x;
		ans = gcd(ans, abs(x-xs));
	}
	cout << ans << endl;
	return 0;
}
