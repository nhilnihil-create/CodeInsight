#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int R,G,B,N;
	cin>>R>>G>>B>>N;
	ll ans=0;
	rep(r,(N/R)+1)
	{
		rep(g,(N/G)+1)
		{
			if(r*R+g*G>N) continue;
			if((N-(r*R+g*G))%B==0) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
