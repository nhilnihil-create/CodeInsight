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
int f(int n)
{
	int ans=0;
	for(int i=(n/4)*4;i<=n;i++)
	ans^=i;
	return ans;
}
int32_t main()
{
	int a=in();int b=in();
	cout<<(f(a-1)^f(b));
	
}