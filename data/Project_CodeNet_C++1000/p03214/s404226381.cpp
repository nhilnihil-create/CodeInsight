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
const int M = 102;
int a[M];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	int sum = 0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum += a[i];
	}
	int df = 1e9,id = -1;
	for(int i=1;i<=n;i++)
	{
		int z = abs(sum-a[i]*n);
		if(z < df)
		{
			df = z;
			id = i;
		}
	}
	cout<<id-1<<"\n";
	return 0;
}