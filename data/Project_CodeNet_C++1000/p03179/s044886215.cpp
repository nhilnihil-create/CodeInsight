#include<bits/stdc++.h>

using namespace std;

const int N = 3100,mod=1e9+7;

typedef long long ll;

int f[N][N];

int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	s="#"+s;
	f[1][1]=1;
	for(int i=2;i<=n;i++)
	{
		if(s[i-1]=='<')
		for(int j=1;j<=i;j++)
		{
			f[i][j]=(f[i][j-1]+f[i-1][j-1])%mod;
		}
		else 
		for(int j=i;j>=1;j--)
		{
			f[i][j]=(f[i][j+1]+f[i-1][j])%mod; 
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=f[n][i];
		ans%=mod;
	}
	cout<<ans<<endl;
	
	
			
	
}