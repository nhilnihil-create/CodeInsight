#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
	int r, g, b, n;
	cin >> r >> g >> b >> n;
	int ans = 0;
	rep(i, n+1){
		if(i % r != 0) continue;
		int adr = i / r;
		rep(j, n+1){
			if(j % g != 0) continue;
			int adg = j / g;
			int adb = n - i - j;
			if(adb < 0) continue;
			if(adb % b == 0){
				ans++;
				// cerr << adr << " " << adg << " " << adb << endl;
			}
		}
	}
	cout << ans << endl;
	return 0;
}