#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli n;

int main(void){
	cin >> n;
	vector<lli> d(n);
	rep(i, n){
		lli a;
		cin >> a;
		while(a%2 == 0){
			a/=2;
			d[i]++;
		}
	}
	lli ans = 0;
	rep(i, n) ans+=d[i];
	cout << ans << endl;
	return 0;
}
