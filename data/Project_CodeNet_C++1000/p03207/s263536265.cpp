#include<bits/stdc++.h>

#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ll unsigned long long 
 
using namespace std;

 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int p[n];
	int maxi=INT_MIN;
	ll sum=0;
	for(int i=0;i<n;i++)
	{
	     cin>>p[i];
	     if(p[i]>maxi)
	     maxi=p[i];
	     sum+=p[i];
	}
	cout<<sum-maxi/2;
	
	return 0;
}
