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
int32_t main()
{
	int n=in();
	vector<int> a(n);
	for(int &i:a)i=in();
	vector<int> p(n+1);
	map<int,int> f;
	int ans=0;
	for(int i=1;i<=n;i++)p[i]+=(p[i-1]+a[i-1]);
	for(int i=0;i<=n;i++)
	{
		if(f[p[i]])ans+=f[p[i]];
		f[p[i]]++;
	}
	cout<<ans;
	
}
