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
	vector<vector<ll int>>nm(n,vector<ll int>(n,0));
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			cin>>nm[i][j];
		}
	}
	int mx1=pw(2,n);
	vector<ll int>cst(mx1,0);
	for(int i=1;i<mx1;++i)
	{
		ll int cnt=0;
		int tmp=i;
		int p1=0;
		while(tmp)
		{
			if(tmp&1)
			{
				int p2=0;
				int tmp1=tmp>>1;
				while(tmp1)
				{
					if(tmp1&1)
					{
						cnt=(cnt+nm[p1][p1+p2+1]);
					}
					tmp1>>=1;
					++p2;
				}
			}
			tmp>>=1;
			++p1;
		}
		cst[i]=cnt;
	}
	vector<ll int>D(mx1,0);
	for(int i=1;i<mx1;++i)
	{
		int m=i;
		int s=m;
		while(s>0)
		{
			D[i]=mx(D[i],D[i^s]+cst[s]);
			s=(s-1)&m;
		}
	}
	
	cout<<D[mx1-1]<<"\n";
	return 0;
}