#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int n, ans = 0, bsum = 0, mnb = INT_MAX;
	cin >> n;
	bool aleq = 1;
	for(int i=0; i<n; i++) {
		int a, b;
		cin >> a >> b;
		if(a != b) {
			aleq = 0;
		}
		if(a < b) {
			ans += b;
		} else if(a == b) {
			ans += b;
		}else{
			bsum += b;
			mnb = min(mnb, b);
		}
	}
	if(aleq)
		return !(cout << 0);
	if(mnb != INT_MAX) {
		ans += bsum - mnb;
	}
	cout << ans;
}