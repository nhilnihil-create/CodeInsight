#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int N;
	cin>>N;
	vector<int> D(N);
	rep(i,N)
	{
		cin>>D[i];
	}
	sort(D.begin(),D.end(),greater<int>());
	int ans=0;
	int now=101;
	for(int d : D)
	{
		if(now>d)
		{
			now=d;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
