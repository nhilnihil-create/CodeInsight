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
	int n,k;
	cin>>n>>k;
	vector<int>nm(n);
	for(int i=0;i<n;++i)
	{
		cin>>nm[i];
	}
	vector<vector<ll int>>D(n,vector<ll int>(k+1,0));
	for(int i=0;i<=nm[0];++i)
	{
		D[0][i]=1;
	}
	for(int i=k-1;i>=0;--i)
	{
		D[0][i]=(D[0][i+1]+D[0][i])%md;
	}
	for(int i=1;i<n;++i)
	{
		D[i][0]=1;
		for(int j=1;j<=k;++j)
		{
			if(j>=nm[i])
			{
				D[i][j]=(((D[i-1][j-nm[i]]-(j==k?0:D[i-1][j+1]))%md)+md)%md;
			}
			else{
				D[i][j]=(((D[i-1][0]-(j==k?0:D[i-1][j+1]))%md)+md)%md;
			}	
		}
		for(int j=k-1;j>=0;--j)
		{
			D[i][j]=(D[i][j+1]+D[i][j])%md;
		}
	}
	cout<<D[n-1][k]<<"\n";
	return 0;
}