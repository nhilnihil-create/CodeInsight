#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;
int n,i,sum,a[2005];
bitset<4000005> dp;
int main()
{
	cin>>n;
	rep(i,n)cin>>a[i];
	rep(i,n)sum+=a[i];
	dp[0]=1;
	rep(i,n)
	{
		dp|=(dp<<a[i]);
	}
	for(i=(sum+1)/2;!dp[i];i++);
	cout<<i<<endl; 
	return 0;
}