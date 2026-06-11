#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
#define INF 1e5
using ll=long long;
using namespace std;


int div_two(ll x)
{
	int ret=0;
	while(x>0&&x%2==0)
	{
		x/=2;
		ret++;
	}
	return ret;
}
int main()
{
	int N;
	cin>>N;
	int ans=INF;
	rep(i,N)
	{
		ll a;
		cin>>a;
		ans=min(ans,div_two(a));
	}
	cout<<ans<<endl;
	return 0;
}
