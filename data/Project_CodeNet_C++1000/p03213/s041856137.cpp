#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
int n,ans;
vector<bool> prime(102,1);
int32_t main()
{
	#ifndef ONLINE_JUDGE
		freopen("in","r",stdin);
		freopen("out","w",stdout);
	#endif
	prime[0]=prime[1]=0;
	for(int i=2;i<=100;i++)
	{
		if(!prime[i])continue;
		for(int j=i*i;j<=100;j+=i)prime[j]=0;

	}
	vector<int> p;
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		if(prime[i])p.push_back(i);
	}
	vector<int> pw;
	for(auto u:p)
	{
		int t=n;int cur=0;
		while(t)
		{
			cur+=t/u;
			t/=u;
		}
		pw.push_back(cur+1);
	}

	vector<int> a(76);
	for(auto i:pw)
	{
		if(i>=75)a[75]++;
		if(i>=25)a[25]++;
		if(i>=15)a[15]++;
		if(i>=5)a[5]++;
		if(i>=3)a[3]++;
	}


	int ans=(a[75]+(a[25])*(a[3]-1)+(a[15]*(a[5]-1))+(a[5])*(a[5]-1)*(a[3]-2)/2);
	cout<<ans;

}
