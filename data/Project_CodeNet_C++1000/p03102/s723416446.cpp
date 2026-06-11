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
	int n=in();int m=in();int c=in();
	vector<int> b(m);
	trav(i,b){i=in();}
	
	vector<int> a(m);
	int ans=0;
	for(int i=0;i<n;i++)
	{
		trav(i,a){i=in();}
		int tmp=c;
		for(int j=0;j<m;j++)
		{
			tmp+=a[j]*b[j];
		}
		if(tmp>0)ans++;
	}
	cout<<ans<<"\n";
	
}