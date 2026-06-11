#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int X;
	cin>>X;
	int ans=1;
	Rep(i,2,X)
	{
		for(int j=2;pow(i,j)<=X;j++)
		{
			ans=max(ans,(int)pow(i,j));
		}	
	}
	cout<<ans<<endl;
	return 0;
}
