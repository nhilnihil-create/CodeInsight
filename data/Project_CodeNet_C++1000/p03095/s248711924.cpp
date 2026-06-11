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
const int mod=1e9+7;
int f[26];
int32_t main()
{
	int n=in();
	string s;
	cin>>s;
	for(auto i:s)
	f[i-'a']++;
	
	int ans=1;
	for(int i=0;i<26;i++)
	{
		ans*=(f[i]+1);
		ans%=mod;
	}	
	ans-=(1-mod);ans%=mod;
	cout<<ans;
	
}
