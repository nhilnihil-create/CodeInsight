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
   ll n;
   cin>>n;
   ll arr[n];
   for(ll i=0;i<n;++i){
   	cin>>arr[i];
   }
   ll dp[n];
   dp[0]=0;
   dp[1] = abs(arr[1]-arr[0]);
   for(ll i=2;i<n;++i){
   	  dp[i] = min(dp[i-1]+abs(arr[i]-arr[i-1]), dp[i-2]+abs(arr[i]-arr[i-2]));
   }
	 cout<<dp[n-1]<<endl;
	return 0;
}

