#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
const int N=2e5+4;
int a[101];
vector<int> moves;
int32_t main()
{
	#ifndef ONLINE_JUDGE
		freopen("in","r",stdin);
		freopen("out","w",stdout);
	#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];

	for(int i=n;i>=1;i--)
	{
		int o=0;
		for(int j=1;j<=i;j++)
		if(a[j]==j)o=j;

		if(o==0){cout<<-1;return 0;}

		moves.push_back(o);
		for(int j=o;j<i;j++)a[j]=a[j+1];
	}
	reverse(moves.begin(),moves.end());
	for(auto i:moves)cout<<i<<"\n";
	
	
}
