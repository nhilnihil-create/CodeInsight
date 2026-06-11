#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define loope(i,a,b) for(ll i=a;i<=b;i++)
#define test() ull t;cin>>t;while(t--)
#define pll pair<ll,ll>
#define puu pair<ull,ull>
#define f first
#define s second
#define pb push_back
#define mkp make_pair
#define ins insert
#define Vint vector<int>
#define Vll vector<ll>
#define Vull vector<ull>
#define nl cout<<endl
#define sp cout<<" "
#define MOD 1000000007
#define all(x) x.begin(),x.end()
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};


int main() 
{
	// ios::sync_with_stdio(0);
	// cin.tie(0);
	// cout.tie(0);
	
	ll n;
	cin>>n;
	vector<vector<int>> v(n,vector<int>(3,0));
	ll dp[n+1][3];
	memset(dp,0,sizeof(dp));
	loop(i,0,n){
		cin>>v[i][0]>>v[i][1]>>v[i][2];
	}	

	loop(i,1,n+1){
		dp[i][0] = v[i-1][0] + max(dp[i-1][1],dp[i-1][2]);
		dp[i][1] = v[i-1][1] + max(dp[i-1][0],dp[i-1][2]);
		dp[i][2] = v[i-1][2] + max(dp[i-1][1],dp[i-1][0]);

	}

	ll ans = 0;

	loop(i,0,3)
		ans = max(ans,dp[n][i]);

	cout<<ans;

}