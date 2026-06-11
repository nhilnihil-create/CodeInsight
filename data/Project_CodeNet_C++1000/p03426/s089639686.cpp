#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define Rep(i,s,f) for(int i=(int)s;i<(int)f;i++)
using ll=long long;
using namespace std;


int main()
{
	int H,W,D;
	cin>>H>>W>>D;
	vector<pair<int,int>> pos(H*W+1,pair<int,int>());
	rep(i,H)
	{
		rep(j,W)
		{
			int a;
			cin>>a;
			pos[a].first=j;
			pos[a].second=i;
		}
	}
	vector<ll> table(H*W+1);
	rep(i,D)
	{
		table[i+1]=0;
		for(int j=i+1+D;j<=H*W;j+=D)
		{
			table[j]=abs(pos[j-D].first-pos[j].first)+abs(pos[j-D].second-pos[j].second)+table[j-D];
		}
	}
	int Q;
	cin>>Q;
	//rep(i,H*W+1)
	//{
	//	cout<<table[i]<<endl;
	//}
	rep(cnt,Q)
	{
		int l,r;
		cin>>l>>r;
		cout<<table[r]-table[l]<<endl;
	}
	return 0;
}
