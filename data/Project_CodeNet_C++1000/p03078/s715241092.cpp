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
	int x=in();int y=in();int z=in();int K=in();
	vector<int> a(x),b(y),c(z);
	trav(i,a)i=in();sort(a.rbegin(),a.rend());
	trav(i,b)i=in();sort(b.rbegin(),b.rend());
	trav(i,c)i=in();sort(c.rbegin(),c.rend());
	vector<int> val;
	for(int i=0;i<x;i++)
	for(int j=0;j<y;j++)
	for(int k=0;k<z;k++)
	{
		if((i+1)*(j+1)*(k+1)<=K)
		val.push_back(a[i]+b[j]+c[k]);
		else break;
		
	}
	
	sort(val.rbegin(),val.rend());
	for(int i=0;i<K;i++)cout<<val[i]<<'\n';
	
}