#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef long long ll;
typedef unsigned int ui;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)

int a[3][105],dp[3][105];

int main()
{
	//freopen("1.in","r",stdin);
	int	n; 
	cin>>n;
	rep(j,1,2)
	rep(i,1,n)cin>>a[j][i];
	rep(j,1,2)
	rep(i,1,n)dp[j][i]=max(dp[j][i-1],dp[j-1][i])+a[j][i];
	cout<<dp[2][n];
}
