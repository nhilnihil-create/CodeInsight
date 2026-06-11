#include<bits/stdc++.h>
using namespace std;
#define md 1000000007
#define ll long long 
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define fastmap mp.reserve(1024);mp.max_load_factor(0.25);
#define fastset st.reserve(1024);st.max_load_factor(0.25);
ll int mpw(ll int a,ll int b,ll int m)
{
	ll int ans=1;
	if(a==0)return 0;
	if(a==1 || b==0)return 1;
	while(b)
	{
		if(b&1)
		{
			ans=(ans*a)%m;
		}
		a=(a*a)%m;
		b>>=1;
	}
	return ans;
}
 
ll int pw(ll int a,ll int b)
{
	ll int ans=1;
	if(a==0)return 0;
	if(a==1 || b==0)return 1;
	while(b)
	{
		if(b&1)
		{
			ans*=a;
		}
		a*=a;
		b>>=1;
	}
	return ans;
}
 
ll int mn(ll int a,ll int b)
{
	if(a<=b)
	{
		return a;
	}
	return b;
}
 
ll int mx(ll int a,ll int b)
{
	if(a>=b)
	{
		return a;
	}
	return b;
}

int main()
{
	fio
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<vector<ll int>>D(n,vector<ll int>(n+1,0));

	for(int i=1;i<=n;++i)
	{
		D[0][i]=1;
	}
	for(int i=1;i<n;++i)
	{
		for(int j=1;j<=i+1;++j)
		{
			if(s[i-1]=='<')
			{
				D[i][j]=(((D[i-1][j-1]-D[i-1][0])%md)+md)%md;
			}
			else{
				D[i][j]=(((D[i-1][n]-D[i-1][j-1])%md)+md)%md;
			}
		}
		for(int j=1;j<=n;++j)
		{
			D[i][j]=(D[i][j]+D[i][j-1])%md;
		}
	}
	
	cout<<(D[n-1][n])<<"\n";
	return 0;
}