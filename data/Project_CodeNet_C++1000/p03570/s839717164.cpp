#include<iostream>
#include<algorithm>
using namespace std;
string s;
int dp[1<<26],c[1<<18];
main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		c[i+1]=c[i]^(1<<(s[i]-'a'));
	}
	int a=1e9;
	for(int i=0;i<s.size();i++)
	{
		a=dp[c[i+1]]||!c[i+1]?dp[c[i+1]]+1:1e9;
		for(int j=1;j<1<<26;j<<=1)a=dp[c[i+1]^j]||!(c[i+1]^j)?min(a,dp[c[i+1]^j]+1):a;
		dp[c[i+1]]=dp[c[i+1]]||!c[i+1]?min(dp[c[i+1]],a):a;
	}
	cout<<a<<endl;
}
