
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
vector<int> a(5);int k;
int solve()
{
	trav(i,a){i=in();}
	k=in();
	for(int i=0;i<5;i++)
	{
		for(int j=i+1;j<5;j++)
		if(a[j]-a[i]>k)return 0;
	}
	return 1;
}
int32_t main()
{
	if(solve())
	puts("Yay!");
	else puts(":(");
	
}