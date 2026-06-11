
#pragma GCC optimize ("O3")
#pragma GCC optimize("unroll-loops")
#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll

inline int in(){int x;scanf("%lld",&x);return x;}

int32_t main()
{
	int r=in();int d=in();int a=in();
	for(int i=0;i<10;i++)
	{
		a=r*a-d;
		cout<<a<<'\n';
	}
	
}