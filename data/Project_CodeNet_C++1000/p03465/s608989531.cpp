#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f[2009];
bitset <4000009> dp;
int main(){
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>a;
	for(b=1; b<=a; b++) cin>>f[b];
	dp[0]=1;
	for(b=1; b<=a; b++){
		c+=f[b];
		dp|=(dp<<f[b]);
	}
	d=0;
	for(b=4000000; b>=c/2+c%2; b--){
		if(dp[b]!=0){
			d=b;
		}
	}
	cout<<d;
	return 0;
}