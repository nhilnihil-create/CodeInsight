#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define pb push_back
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,z,w;
	cin>>n>>z>>w;
	int a[n];
	for(int i= 0; i<n; i++) cin>>a[i];
	int g = abs(a[n-1]-w);
	int ans = 0;
	for(int i = 0; i<n; i++)
		a[i] = abs(a[n-1]-a[i]);
	cout<<max(g,a[n-2])<<endl;
	return 0;
}