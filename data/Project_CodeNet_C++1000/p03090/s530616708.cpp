#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



signed main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   

#ifndef ONLINE_JUDGE
	if(fopen("INPUT.txt","r"))
	{
	freopen ("INPUT.txt" , "r" , stdin);
	freopen ("OUTPUT.txt" , "w" , stdout);
	}
#endif  

	int n;
	cin>>n;
	vector<pair<int,int> >ans;
	if(n&1)
	{
		for(int i=1;i<=n-1;i++)
		{
			for(int j=i+1;j<=n-1;j++)
			{
				if(i+j==n)
					continue;
				ans.push_back({i,j});
			}
		}
		for(int i=1;i<=n-1;i++)
			ans.push_back({i,n});
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(i+j==n+1)
					continue;
				ans.push_back({i,j});
			}
		}		
	}
	cout<<ans.size()<<"\n";
	for(auto i:ans)
		cout<<i.first<<" "<<i.second<<'\n';
	
}
