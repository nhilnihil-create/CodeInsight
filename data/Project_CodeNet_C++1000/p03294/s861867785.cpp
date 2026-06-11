#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

int n;

int main(void){
	cin >> n;
	lli ans = 0;
	rep(i, n){
		lli a;
		cin >> a;
		ans += a-1;
	}
	cout << ans << endl;
	return 0;
}
