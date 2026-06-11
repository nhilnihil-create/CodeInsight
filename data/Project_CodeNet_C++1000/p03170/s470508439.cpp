#include <bits/stdc++.h>

#define FLASH ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long int
#define MAX 1e9
#define MIN -1e9
#define mod 1000000007
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define output(x) cout << ( x ? "Yes" : "No" ) << '\n' ;
#define N 1000005
using namespace std;

void solve(){
	int n,k;
	cin >> n >> k ;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int dp[k + 1] = {};
	for(int i = 0; i <= k; i++){
		for(auto val : a){
			if(i - val >= 0 && dp[i - val] == 0)
				dp[i] = 1;
		}
	}
	cout << (dp[k] == 1 ? "First" : "Second");
}
int32_t main()
{
	FLASH
	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
