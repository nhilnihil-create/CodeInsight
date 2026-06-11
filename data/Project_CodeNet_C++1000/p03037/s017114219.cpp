
#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll

inline int in(){int x;scanf("%lld",&x);return x;}
int32_t main()
{
	int n=in();int m=in();
	int l=-1,r=INT_MAX;
	int x,y;
	for(int i=0;i<m;i++)
	{
		x=in();y=in();
		l=max(l,x);
		r=min(r,y);
	}
	
	cout<<max(0LL,r-l+1);
	
}