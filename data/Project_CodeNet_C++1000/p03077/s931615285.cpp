#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n;

int main(void){
	cin >> n;
	vector<lli> c(5);
	lli minv = 1e18;
	rep(i, 5){
		cin >> c[i];
		minv = min(minv, c[i]);
	}
	lli ans = (n+minv-1)/minv+4;
	cout << ans << endl;
	
	return 0;
}
