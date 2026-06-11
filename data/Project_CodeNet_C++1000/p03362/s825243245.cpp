#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
const int N=56001;
vector<bool> prime(N,1);
vector<int> p;

int32_t main()
{
	#ifndef ONLINE_JUDGE
		freopen("in","r",stdin);
		freopen("out","w", stdout);
	#endif

	prime[0]=prime[1]=0;
	for(int i=2;i<N;i++)
	{
		if(!prime[i])continue;
		for(int j=i*i;j<N;j+=i)prime[j]=0;
	}
	int rem=0;
	for(int i=0;i<=55555;i++)
	{
		if(prime[i])
		{
			rem=i%5;
			if(rem==1)p.push_back(i);
		}
	}
	
	int n;cin>>n;
	for(int i=0;i<n;i++)cout<<p[i]<<" ";


	

}