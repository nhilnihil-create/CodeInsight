//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		a,b,c,h,i,j,k,l,m,n,x,y;
	ll		ans = 0;
	string	s;
	cin >> n >> k >> s;
	vector<ll> aa(n+1);
	s += '1';
	a = 0;
	c = -1;
	for(i=1;i<n;i++) {
		if (s[i-1]=='0' && s[i]=='1') {
			c = i;
		}
		if (s[i]=='1') a++;
		else {
			if (c>0) {
				aa[c] = a;
			}
			c = -1;
			a = 0;
		}
	}
	if (c>0) aa[c] = a;
	//for(i=0;i<=n;i++) cout << aa[i] << endl;
	c = 0;
	for(i=1;i<=n;i++) {
		if (s[i-1]=='0' && s[i]=='1') {
			c++;
			if (c==k) break;
		}
	}
	if (c<k || i==n) {
		cout << n << endl;
		return 0;
	}
	j = 0;
	ans = i+1;
	//cout << i << ' ' << c << ' ' << endl;
	for(i++;i<=n;i++) {
		if (s[i-1]=='0' && s[i]=='1') {
			for(j++;j<i;j++) {
				if (s[j-1]=='0' && s[j]=='1') {
					if (i==n) x = i-j;
					else x = i-j+aa[i];
					ans = max(ans , x);
					break;
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}
