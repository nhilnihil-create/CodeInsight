#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n;

int main(void){
	cin >> n;
	vector<lli> h(n);
	rep(i, n)cin >> h[i];
	lli ans = h[0];
	rep(i, n-1){
		if(h[i] < h[i+1]) ans+=h[i+1]-h[i];
	}
	cout << ans << endl;
	return 0;
}
