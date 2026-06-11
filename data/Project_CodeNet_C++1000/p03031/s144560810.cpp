#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
#define sz(x) (int)(x).size();
#define all(x) x.begin(), x.end()
#define trav(i,a) for(auto &i:a) 
inline int in(){int x;scanf("%lld",&x);return x;}
int32_t main()
{
	int n=in();int m=in();
	vector<int> p(m);
	vector<int> k(m);
	int x;
	for(int i=0;i<m;i++)
	{
		int k1=in();
		for(int j=0;j<k1;j++)
		{
			x=in();
			x--;
			k[i]|=(1<<x);
		}
	}
	trav(i,p)i=in();int ans=0;
	for(int mask=0;mask<(1<<n);mask++)
	{
		bool ok=1;
		for(int j=0;j<m;j++)
		{
			if(__builtin_popcountll(mask&k[j])%2==p[j])ok&=1;
			else ok&=0;
		}
		if(ok)ans++;
	}
	cout<<ans;
	
}