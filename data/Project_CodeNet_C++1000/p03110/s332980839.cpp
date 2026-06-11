#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)

int main() {
	int n; cin >> n;
	long double JPY=0; long double BTC=0;
	rep(i,n) {
		long double x; string u; cin >> x >> u;
		if(u=="BTC") BTC+=x;
		else JPY+=x;
	}
	long double ans=JPY+BTC*380000;
	cout << ans << endl;
}