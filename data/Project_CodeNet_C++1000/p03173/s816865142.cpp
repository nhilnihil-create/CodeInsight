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
	vector<ll int>nm(n);
	vector<ll int>sm(n);
	for(int i=0;i<n;++i)
	{
		cin>>nm[i];
		if(i==0)
		{
			sm[i]=nm[i];
		}
		else{
			sm[i]=sm[i-1]+nm[i];
		}
	}
	vector<vector<ll int>>D(n,vector<ll int>(n,-1));
	for(int i=0;i<n;++i)
	{
		for(int j=i;j>=0;--j)
		{
			if(i==j)
			{
				D[j][i]=0;
			}
			else if(i-j==1)
			{
				D[j][i]=nm[i]+nm[j];
			}
			else{
				for(int x=j;x<i;++x)
				{
					if(D[j][i]==-1)
					{
						D[j][i]=D[j][x]+D[x+1][i]+sm[i]-(j==0?0:sm[j-1]);
					}
					else{
						D[j][i]=mn(D[j][i],D[j][x]+D[x+1][i]+sm[i]-(j==0?0:sm[j-1]));
					}
					
				}
			}
		}
	}
	cout<<D[0][n-1]<<"\n";
	return 0;
}