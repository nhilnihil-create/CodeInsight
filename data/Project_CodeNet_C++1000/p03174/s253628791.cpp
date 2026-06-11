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
vector<vector<ll int>>D; 
int main()
{
	fio
	int n;
	cin>>n;
	vector<vector<char>>nm(n,vector<char>(n));
	vector<ll int>shf(n+1);
	shf[0]=1;
	for(int i=1;i<=n;++i)
	{
		shf[i]=shf[i-1]*2;
	}
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			cin>>nm[i][j];
		}
	}
	D.clear();
	int mx1=shf[n];
	D.resize(n,vector<ll int>(mx1,0));
	for(int j=0;j<n;++j)
	{
		if(nm[0][j]=='1')
		{
			D[0][shf[j]]=1;
		}
	}
	for(int i=1;i<n;++i)
	{
		for(int j=0;j<mx1;++j)
		{
			if(__builtin_popcount(j)==i)
			{
				for(int k=0;k<n;++k)
				{
					if(nm[i][k]=='1' && ((j&(shf[k]))==0))
					{
						D[i][j|(shf[k])]=(D[i][j|(shf[k])]+D[i-1][j])%md;
					}
				}
			}
		}
	}
	cout<<D[n-1][mx1-1]<<"\n";
	return 0;
}