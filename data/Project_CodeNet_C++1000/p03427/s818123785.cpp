#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	string N;
	cin>>N;
	int ans=0;
	rep(i,N.size())
	{
		ans+=(int)(N[i]-'0');
	}
	int val=(N[0]-'0')-1;
	rep(i,N.size()-1)
	{
		val+=9;
	}
	cout<<max(ans,val)<<endl;
	return 0;
}
