#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
const ll mod = 1e9 + 7;
ll inf = 1e16;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)



int main()
{
   fastio;
   ll n,k;
   cin>>n>>k;
   ll arr[n];
   for(ll i=0;i<n;++i){
   	cin>>arr[i];
   }
   ll dp[n];
   dp[0]=0;
   for(ll i=1;i<n;++i){
   	    ll val = inf;
   	   for(int j=i-1;j>=0 && j>=i-k;--j){
   	   	     val = min(val, dp[j]+abs(arr[i]-arr[j]));
		}
		dp[i] = val;
   }
	 cout<<dp[n-1]<<endl;
	return 0;
}

