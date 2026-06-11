#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n, k;

int main(void){
	cin >> n >> k;
	vector<lli> h(n);
	rep(i, n) cin >> h[i];
	sort(h.begin(), h.end());
	lli ans = INT_MAX;
	rep(i, n){
		if(k+i-1 >= n) break;
		ans = min(ans, h[k+i-1]-h[i]);
	}
	cout << ans << endl;
	return 0;
}
