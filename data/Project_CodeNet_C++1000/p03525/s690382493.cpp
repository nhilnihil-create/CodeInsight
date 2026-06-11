#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int N;
	cin>>N;
	vector<int> D(N+1);
	D[0]=0;
	rep(i,N) cin>>D[i+1];
	sort(D.begin(),D.end());
	rep(i,N+1)
	{
		if(i%2==1)
		{
			D[i]=24-D[i];
		}
	}
	int ans=24;
	for(int i=0;i<N;i++)
	{
		for(int j=i+1;j<N+1;j++)
		{
			int diff=abs(D[i]-D[j]);
			ans=min(ans,min(diff,24-diff));
		}
	}
	cout<<ans<<endl;
	return 0;
}
