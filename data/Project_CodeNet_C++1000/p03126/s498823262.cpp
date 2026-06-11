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
int f[50];
int32_t main()
{
	int n=in();int m=in();int k,x;
	for(int i=0;i<n;i++)
	{
		cin>>k;
		for(int j=0;j<k;j++){x=in();f[x]++;}
	}
	int ans=0;
	for(int i=0;i<50;i++)
	{
		if(f[i]==n)ans++;
	}
	cout<<ans;
	
	
	
}