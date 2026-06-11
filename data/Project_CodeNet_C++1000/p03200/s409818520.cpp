#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	string S;
	cin>>S;
	int N=S.size();
	ll ans=0;
	int black=0;
	rep(i,N)
	{
		if(S[i]=='B')
		{
			black++;
		}
		else
		{
			ans+=black;
		}
	}
	cout<<ans<<endl;
	return 0;
}
