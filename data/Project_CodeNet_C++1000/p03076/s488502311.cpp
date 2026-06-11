
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
	
	vector<int> a(5);
	trav(i,a){i=in();}
	int ans=accumulate(all(a),0LL);
	int t;int mx=0;
	for(auto i:a)
	{
		t=(i+9)/10;
		t*=10;
		ans+=t-i;
		mx=max(mx,t-i);
	}
	cout<<ans-mx;
	
}