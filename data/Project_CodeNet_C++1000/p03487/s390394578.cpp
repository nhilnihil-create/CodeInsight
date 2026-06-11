#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int N;
	cin>>N;
	map<int,int> m;
	rep(i,N)
	{
		int a;
		cin>>a;
		m[a]++;
	}
	int ans=0;
	for(auto p : m)
	{
		if(p.first>p.second)
		{
			ans+=p.second;
		}
		else
		{
			ans+=p.second-p.first;
		}
	}
	cout<<ans<<endl;
	return 0;
}
