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
	int n=in();int tot=0;
	vector<int>a(n);trav(i,a)i=in();
	int neg=count_if(all(a),[&](int x){return x<0;});
	//cout<<neg<<'\n';
	int mn=INT_MAX;for(auto i:a){mn=min(mn,abs(i));tot+=abs(i);}
	
	if(neg%2==1){tot-=2*mn;}
	cout<<tot;
	
}