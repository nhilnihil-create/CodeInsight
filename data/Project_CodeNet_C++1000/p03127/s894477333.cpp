//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

/* 最大公約数 (ユークリッドの互除法) */
long long gcd(long long m, long long n) {
	long long temp;
	if (n > m) swap(m , n);
	while (m % n != 0)
	{
		temp = n;
		n = m % n;
		m = temp;
	}
	return n;
}

int main() {
	ll		b,c,d,w,h,i,j,k,l,m,n,x,y,z;
	ll		ans = 0;
	string	s;
	cin >> n;
	vector<ll>	a(n);
	for(i=0;i<n;i++) cin >> a[i];
	//vector<ll>	dp(n+1,INFL);
	//vector<vector<ll>>	dp2(x , vector<ll>(y,INFL));
	ans = gcd(a[0],a[1]);
	for(i=2;i<n;i++) {
		ans = gcd(ans,a[i]);
	}

	cout << ans << endl;
	return 0;
}
