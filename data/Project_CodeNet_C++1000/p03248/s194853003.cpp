#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	s = "#"+s;
	int n=sz(s)-1;
	if(s[n]=='1' || s[1]=='0')
	{
		cout<<"-1\n";
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		if(s[i]!=s[n-i])
		{
			cout<<"-1\n";
			return 0;
		}
	}
	for(int i=1;i<=n-1;i++)
	{
		if(s[i]=='0')
			continue;
		int j=i+1;
		while(j<n-1 && s[j]=='0')
			j++;
		for(int k=i;k<j;k++)
		{
			cout<<j<<" "<<k<<"\n";
		}
	}
}