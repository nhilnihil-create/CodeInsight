//----------BHAVIK DIWANI(PICT_COMP)---------------
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define test ll t; cin>>t; while(t--)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007
#define ll long long
#define int long long
#define ull unsigned long long
#define MAX 1000005
#define pb push_back
#define mkp make_pair
#define vi vector<int>
#define pii pair<int,int>
#define endl '\n'
#define vs vector<string>
#define mii map<int,int>
#define msi map<string,int>
#define vpii vector< pair<int, int > >
#define vpsi vector< pair< string ,int > >
#define forci(p,q) for(int i=p;i<q;i++)

using namespace std;
const int size1=405;
int a[size1]={0};
int pref[size1]={0};
int dp[size1][size1];
int calc(int ini,int fin){
	if(dp[ini][fin]!=-1)
		return dp[ini][fin];
	if(ini+1==fin)
		return dp[ini][fin]=a[ini]+a[fin];
	if(ini==fin)
		return dp[ini][fin]=0;
	int mn=1e18+5;
	for(int i=ini;i<fin;i++){
		int ans=calc(ini,i)+calc(i+1,fin)+pref[fin]-pref[ini-1];
		mn=min(ans,mn);
	}
	dp[ini][fin]=mn;
	return dp[ini][fin];
}
int solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pref[i]=pref[i-1]+a[i];
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++)
			dp[i][j]=-1;
	}
	cout<<calc(1,n);
	return 0;
}
signed main()
{
	fastio;
	solve();
}

