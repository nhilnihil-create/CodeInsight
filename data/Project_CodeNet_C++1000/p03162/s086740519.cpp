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

struct all{
	ll a,b,c;
};
void solve()
{



}

int main()
{
   fastio;
   ll n;
   cin>>n;
   all arr[n];
   for(int i=0;i<n;++i){
   	cin>>arr[i].a>>arr[i].b>>arr[i].c;
   }
   all dp[n+1];
   dp[0].a = dp[0].b = dp[0].c = 0;
   for(int i=1;i<=n;++i){
   	   dp[i].a = arr[i-1].a + max(dp[i-1].b, dp[i-1].c);
   	   dp[i].b = arr[i-1].b + max(dp[i-1].a, dp[i-1].c);
   	   dp[i].c = arr[i-1].c + max(dp[i-1].a , dp[i-1].b);
   }
   cout<<max(dp[n].a, max(dp[n].b , dp[n].c))<<endl;
   
   return 0;
}

