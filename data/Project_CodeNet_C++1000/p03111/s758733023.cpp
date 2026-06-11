#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		a,b,c,d,w,h,i,j,k,m,n,x,y,z;
	ll		ans = INFL;
	cin >> n >> a >> b >> c;
	vector<ll>	l(n);
	for(i=0;i<n;i++) cin >> l[i];

	for(i=0;i<(1<<(n*2));i++) {
		x = y = z = k = 0;
		for(j=0;j<n;j++) {
			if (((i>>(j*2)) & 3)==1) { if (x!=0) k+=10; x+=l[j]; }
			if (((i>>(j*2)) & 3)==2) { if (y!=0) k+=10; y+=l[j]; }
			if (((i>>(j*2)) & 3)==3) { if (z!=0) k+=10; z+=l[j]; }
		}
		if (x==0 || y==0 || z==0) continue;
		ans = min(ans , k+abs(a-x)+abs(b-y)+abs(c-z));
	}
	cout << ans << endl;
	return 0;
}
