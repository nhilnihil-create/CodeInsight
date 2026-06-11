#include<bits/stdc++.h>
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define pb push_back
#define sz(x) (int)x.size()
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define F first
#define S second
#define watch(x) cerr << "\n" << (#x) << " = " << (x) << "\n"
using namespace std;
ll h, w, dp[1005][1005];
char a[1005][1005];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	cin >> h >> w;
	for(int i = 1; i <= h; ++i){
		for(int j = 1; j <= w; ++j){
			cin >> a[i][j];
		}
	}

	dp[1][1] = 1;
	for(int i = 2; i <= h; ++i){
		if(a[i][1] == '#')
			break;
		dp[i][1] = 1;
	}

	for(int i = 2; i <= w; ++i){
		if(a[1][i] == '#')
			break;
		dp[1][i] = 1;
	}

	for(int i = 2; i <= h; ++i){
		for(int j = 2; j <= w; ++j){
			if(a[i][j] == '.'){
				dp[i][j] = (dp[i - 1][j] % mod + dp[i][j - 1] % mod) % mod;
			}
		}
	}

	cout << dp[h][w];
	return 0;
}