#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	ll N;
	cin>>N;
	ll mn=1e15+1;
	rep(i,5)
	{
		ll v;
		cin>>v;
		mn=min(mn,v);
	}
	cout<<4+(N+mn-1)/mn<<endl;
	return 0;
}
