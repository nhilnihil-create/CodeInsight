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
	int a[n+1];
	int temp[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		temp[i]=a[i];
		a[i]=i-a[i];
		// cout<<a[i]<<" ";
	}

	int cnt=n;
	vector<int>ans;
	while (cnt--)
	{
		bool flag=false;
		for(int i=n;i>=1;i--)
		{
			if(a[i]==0)
			{
				flag=true;
				ans.push_back(temp[i]);
				a[i]=-1;
				for(int j=i+1;j<=n;j++)
				{
					a[j]--;
				}
				break;
			}
		}

		if(!flag)
		{
			cout<<-1;
			return 0;
		}
	}
	reverse(ans.begin(),ans.end());
	for(int i=0;i<n;i++)
	{
		if(ans[i]>i+1)
		{
			cout<<-1;
			return 0;
		}
	}
	for(auto i:ans)
		cout<<i<<'\n';

}
