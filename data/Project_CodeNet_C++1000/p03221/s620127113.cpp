#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
const int N=1e5+3;
int n,m;
vector<pair<int,int>> ad[N];
string ans[N];
string dig(int x)
{
	string a=to_string(x);
	int z=6-a.length();
	a=string(z,'0')+a;
	return a;

}
int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	
	cin>>n>>m;
	int a,b;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		ad[a].push_back({b,i});
	}
	for(int i=1;i<=n;i++)
	{
		sort(ad[i].begin(),ad[i].end());

		for(int j=0;j<ad[i].size();j++)
		{
			int ii=ad[i][j].second;
			ans[ii]=dig(i)+dig(j+1);
		}
	}

	for(int i=0;i<m;i++)
	{
		cout<<ans[i]<<"\n";

	}


	

	
	
	
}