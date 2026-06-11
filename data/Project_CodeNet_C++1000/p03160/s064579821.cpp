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
	ll dp[n+1],v[n];
	memset(dp,0,sizeof(dp));
	loop(i,0,n)
		cin>>v[i];
	dp[2] = abs(v[1]-v[0]);
	loop(i,3,n+1){
		dp[i] = min(dp[i-2] + abs(v[i-1]-v[i-3]),dp[i-1] + abs(v[i-1]-v[i-2]));
	}

	cout<<dp[n];
}