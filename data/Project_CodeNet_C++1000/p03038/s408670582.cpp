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
#define x first
#define y second
int32_t main()
{
	int n=in();int m=in();int d,b;
	vector<pair<int,int>>a;
	for(int i=0;i<n;i++)
	{
		d=in();a.push_back({d,1});
	}
	for(int i=0;i<m;i++)
	{
		d=in();b=in();a.push_back({b,d});
	}
	sort(all(a));
	reverse(all(a));
	int cnt=0,ans=0,c;
	for(auto i:a)
	{
		b=i.y;c=i.x;
		cnt+=b;ans+=c*b;
		if(cnt>n){ans-=c*(cnt-n);break;}
	}
	cout<<ans;
	
}