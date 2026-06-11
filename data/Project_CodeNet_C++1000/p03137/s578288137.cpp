#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n, m;

int main(void){
	cin >> n >> m;
	vector<lli> x(m);
	rep(i, m) cin >> x[i];
	sort(x.begin(), x.end());
	if(m == 1){
		cout << 0 << endl;
		return 0;
	}
	vector<lli> e(m-1);
	rep(i, m-1) e[i] = abs(x[i+1]-x[i]);
	sort(e.begin(), e.end());
	lli ans = 0;
	rep(i, m-n) ans+=e[i];
	cout << ans << endl;
	return 0;
}
