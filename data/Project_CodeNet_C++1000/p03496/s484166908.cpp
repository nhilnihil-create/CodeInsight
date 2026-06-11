#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
#define all(x) x.begin(), x.end()
#define trav(i,a) for(auto &i:a) 
inline int in(){int x;scanf("%lld",&x);return x;}
const int N=60;
int a[N];
int32_t main()
{
	int n=in();
	vector<pair<int,int>> mv;
	for(int i=1;i<=n;i++)a[i]=in();
	
	int mx=*max_element(a+1,a+n+1);
	int mn=*min_element(a+1,a+n+1);
	
	if(abs(mx)>abs(mn))
	{
		int id=max_element(a+1,a+n+1)-a;
		for(int i=1;i<=n;i++)
		{
			if(i!=id)
			{
				mv.push_back({id,i});
				a[i]+=a[id];
			}
		}
		for(int i=1;i<n;i++)
		{
			a[i+1]+=a[i];
			mv.push_back({i,i+1});
		}
	}
	else
	{
		int id=min_element(a+1,a+n+1)-a;
		for(int i=1;i<=n;i++)
		{
			if(i!=id)
			{
				mv.push_back({id,i});
				a[i]+=a[id];
			}
		}
		for(int i=n-1;i>=1;i--)
		{
			a[i]+=a[i+1];
			mv.push_back({i+1,i});
		}
	}
	cout<<mv.size()<<"\n";
	for(auto i:mv)
	{
		cout<<i.first<<" "<<i.second<<"\n";
	}
	
	//for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	
	
}
