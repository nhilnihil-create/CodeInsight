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
	int n;
	cin >> n;
	bool flag = true;
	ll ans = 0, tot = 0;
	rep(i, n){
		int ina, inb;
		cin >> ina >> inb;
		if(ina > inb){
			if(ans == 0 || ans > inb){
				ans = inb;
			}
		}
		if(ina != inb) flag = false;
		tot = tot + (ll)ina;
	}
	if(flag == true){
		cout << 0 << endl;
		return 0;
	}
	
	ans = tot - ans;
	cout << ans << endl;

	return 0;
}