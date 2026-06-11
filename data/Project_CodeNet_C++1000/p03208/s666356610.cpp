#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
#define INF 1<<31-1
using ll=long long;
using namespace std;


int main()
{
	int N,K;
	cin>>N>>K;
	vector<ll> h(N);
	rep(i,N) cin>>h[i];
	sort(h.begin(),h.end(),greater<ll>());
	ll ans=INF;
	rep(i,N-K+1)
	{
		ans=min(ans,h[i]-h[i+K-1]);
	}
	cout<<ans<<endl;
	return 0;
}
