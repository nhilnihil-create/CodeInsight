#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n, m;

int main(void){
	cin >> n >> m;
	vector<pair<lli, lli>> d(n);
	rep(i, n){
		int a, b;
		cin >> a >> b;
		d[i] = {a, b};
	}
	sort(d.begin(), d.end());
	lli ans = 0;
	rep(i, n){
		if(m == 0) break;
		ans += d[i].first*min(d[i].second, m);
		m-=min(d[i].second, m);
	}
	cout << ans << endl;
	return 0;
}
