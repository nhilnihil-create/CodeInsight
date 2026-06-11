#include <bits/stdc++.h>

#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>

using namespace std;

const int maxn = 1e5+10;

ll dp[maxn][2];

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vi vs(n);
	dp[0][0] = 0;
	dp[0][1] = -(1LL<<60);
	for(int i=0;i<n;++i){
		int x;cin>>x;
		dp[i+1][0] = max(dp[i][0]+x,dp[i][1]-x);
		dp[i+1][1] = max(dp[i][0]-x,dp[i][1]+x);
	}
	cout<<dp[n][0]<<endl;
	return 0;
}