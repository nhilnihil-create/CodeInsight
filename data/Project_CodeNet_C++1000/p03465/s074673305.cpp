#include<bits/stdc++.h>
using namespace std;
bitset<4000001>dp;
int n,a[2003],sum;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i],sum+=a[i];
	dp[0]=1;
	for(int i=0;i<n;i++)
		dp|=(dp<<a[i]);
	for(int i=0;i<=4000000;i++)
		if(dp[i]&&i*2>=sum){
			cout<<i;
			return 0;
		}
}