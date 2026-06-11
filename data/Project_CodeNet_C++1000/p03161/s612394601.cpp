#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i,x,n) for(ll i=x;i<n;i++)
#define S(v) sort(v.begin(), v.end())
#define print(v) for(auto i:v)cout<<i<<" "
#define ff first
#define ss second
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	ll t= 1;
	// cin>>t;
	while(t--)
	{
		ll n, k;
		cin>>n>>k;
		vector<ll> v(n);
		loop(i,0,n)cin>>v[i];
		ll dp[n];
		dp[0] = 0;
		dp[1] = abs(v[1] - v[0]);
		loop(i, 1, n){
			dp[i] = LONG_LONG_MAX;
			loop(j, max((ll)0, i - k), i){
				dp[i] = min(dp[i], abs(v[i] - v[j]) + dp[j]);
			}

		}
		cout<<dp[n-1]<<endl;

		
	}
} 