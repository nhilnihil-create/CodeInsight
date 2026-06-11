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
using ld=long double;
int32_t main()
{
	ld ans=0;
	int n=in();ld btc=380000.0 ;
	string s;ld mon;
	while(n--)
	{
		cin>>mon>>s;
		if(s=="BTC")ans+=mon*btc;
		else ans+=mon;
	}
	cout<<fixed<<setprecision(12)<<ans;
	
}