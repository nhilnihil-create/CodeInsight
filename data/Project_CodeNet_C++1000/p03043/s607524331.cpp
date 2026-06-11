//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

ll pow2(long long n) {
	ll ret = 1;
	ll x = 2;
    while (n > 0) {
        if (n & 1) ret *= x;  // n の最下位bitが 1 ならば x^(2^i) をかける
        x *= x;
        n >>= 1;  // n を1bit 右にずらす
    }
    return ret;
}

int main() {
	ll		a,b,c,h,i,j,k,l,m,n,x,y;
	ll		ans = 0;
	string	s;
	cin >> n >> k;
	long double p = 0.0;
	vector<ll> cc;
	for(i=n;i>=1;i--) {
		c = 0;
		a = i;
		while(a<k) {
			c++;
			a *= 2;
		}
		//cc.push_back(c);
		p += (long double)1/n/pow2(c);
	}
	/*
	x = 0;
	for(i=0;i<cc.size();i++) {
		x += pow2(c-cc[i]);
	}
	//cout << x << ' ' << c << ' ' << pow2(c) << endl;
	p = (long double)x / pow2(c) / n;
	*/
	cout << fixed << setprecision(10);
	cout << p << endl;
	return 0;
}
