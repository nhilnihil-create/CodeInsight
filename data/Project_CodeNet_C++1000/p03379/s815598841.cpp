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
	int l=n/2;int h=l+1;
	l--;h--;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++)a[i]=in();
	
	b=a;
	sort(all(b));
	int lo=b[l];int hi=b[h];
	
	for(int i=0;i<n;i++)
	{
		if(a[i]<=lo)cout<<hi<<"\n";
		else cout<<lo<<"\n";
	}
	
}