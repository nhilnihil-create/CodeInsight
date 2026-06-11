#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
const int N=2e5+5;
int n,m;
int a[501][501];
int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)cin>>a[i][j];

	vector<tuple<int,int,int,int>> ans;
	for(int i=0;i<n;i++)
		for(int j=0;j<m-1;j++)
		{
			if(a[i][j]%2)
			{
				a[i][j]--;
				a[i][j+1]++;
				ans.push_back({i+1,j+1, i+1,j+2});
			}
		}
	
	for(int i=0;i<n-1;i++)
		{
			if(a[i][m-1]%2)
			{
				a[i][m-1]--;
				a[i+1][m-1]++;
				ans.push_back({i+1,m, i+2,m});
			}
		}

	cout<<ans.size()<<"\n";
	for(auto i:ans)
	{
		int a,b,c,d;
		tie(a,b,c,d)=i;
		cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
	}


	
}