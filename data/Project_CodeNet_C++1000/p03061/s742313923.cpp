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
	int n=in();
	vector<int> a(n);
	trav(i,a)i=in();
	vector<int> rg(n);
	vector<int> lg(n);
	rg[n-1]=a[n-1];lg[0]=a[0];
	if(n==1){cout<<a[0];return 0;}
	if(n==2){cout<<max(a[0],a[1]);return 0;}
	int g=a[0];
	for(int i=1;i<n;i++)
	{
		g=__gcd(g,a[i]);
		lg[i]=g;
	}
	g=a[n-1];
	for(int i=n-2;i>=0;i--)
	{
		g=__gcd(g,a[i]);
		rg[i]=g;
	}
	int mx=max(lg[n-2],rg[1]);
	for(int i=1;i<n-1;i++)
	{
		mx=max(mx,__gcd(lg[i-1],rg[i+1]));
	}
	cout<<mx;
	
	
}