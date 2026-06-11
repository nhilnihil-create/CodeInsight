#include<bits/stdc++.h>
#define ll 				long long
#define ld 				long double
#define fastio 			ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define debug(x) 		cerr<<#x<<" "<<x<<endl
#define cina(a,n) 		for(ll i = 0;i<n;i++)	cin>>a[i];
#define couta(a,n) 		for(ll i = 0;i<n;i++) cout<<a[i]<<" ";
#define fauto(ar)		for(auto x : ar)	cout<<x<<" ";
#define mod 			1000000007
#define inf				100100100100100100
#define siz 			100005
#define f 				first
#define s 				second
#define pb 				push_back
#define endl 			"\n"
#define ci 				cin.ignore()
using namespace std;
ll dp[405][405],prefixsum[405];
ll getsum(ll i,ll j)
{
	if(i == 0)
	return prefixsum[j];
	return prefixsum[j] - prefixsum[i-1];
}
ll getans(ll *a,ll i,ll j)
{
	if(i >= j)
	return 0;
	if(dp[i][j] != -1)
	return dp[i][j];
	ll k,ans = inf,curr;
	for(k=i;k<j;k++)
	{
		curr = getans(a,i,k) + getans(a,k+1,j) + getsum(i,j);
		ans = min(ans,curr);
	}
	return dp[i][j] = ans;
}
int main()
{
	ll n,i,j;
	cin>>n;
	ll a[n];
	cina(a,n);
	
	prefixsum[0] = a[0];
	for(i=1;i<n;i++)
	prefixsum[i] = prefixsum[i-1] + a[i];
	
	for(i = 0;i<n;i++)
	for(j = 0;j<n;j++)
	dp[i][j] = -1;
	
	cout<<getans(a,0,n-1);
	

	
}