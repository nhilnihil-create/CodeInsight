#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define fr(i,k,n) for (int i = k; i < n; ++i)
#define fri(i,k,n) for (int i = k; i >= n; --i)
#define INF (int)1e9
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define all(arr) arr.begin(),arr.end()

void boost(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve(){
	int n;
	cin>>n;
	vector<vector<ll>> arr(n,vector<ll>(n));
	fr(i,0,n)
	fr(j,0,n)
	cin>>arr[i][j];
	vector<ll> dp(1<<n,0);
	vector<vector<ll>> len(1<<n);
	for(int mask=1;mask<(1<<n);mask++){
		vector<int> cur;
		len[__builtin_popcount(mask)].pb(mask);
		fr(i,0,n)
			if(mask&(1<<i))
				cur.pb(i);	
		fr(i,0,cur.size())
			fr(j,i,cur.size())
				dp[mask]+=arr[cur[i]][cur[j]];
	}
	fr(l,1,n+1)
		for(auto x: len[l])
			for(int s=x;s;s=(s-1)&x)
				dp[x]=max(dp[x],dp[s]+dp[s^x]);
	cout<<dp[(1<<n)-1]<<endl;
	return;
}

int main()
{
	boost();
	
	int tc=1;
	//cin>>tc;
	while(tc--)
		solve();
	return 0;
}