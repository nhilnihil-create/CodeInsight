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
	int n, z, w;
	cin >> n >> z >> w;
	vector<int> a(n);
	rep(snip_i, n) cin >> a.at(snip_i);
	if(n == 1){
		int ans = fabs(a.at(0) - w);
		cout << ans << endl;
		return 0;
	}
	int ans = fabs(a.back() - w);
	int add = fabs(a.at(n-2) - a.at(n-1));
	ans = max(ans, add);
	cout << ans << endl;
	return 0;
}