#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define bitcnt(v) __builtin_popcount(v)
#define all(v) v.begin(), v.end()

bool dp[100003];
vector<int> a;
int n, k; 

void solution(){
	cin >> n >> k;
	a = vector<int>(n); for(auto& x : a) cin >> x;
	// Game Theory DP - 
	// here state only depends on number of stones left 
	// and whos turn it is to move
	memset(dp,0,sizeof(dp));
	for(int cur = 0; cur <= k; cur++){
		for(int x : a){
			if(cur >= x && !dp[cur-x]) dp[cur] = 1;

		}
	}
	if(dp[k]) cout << "First\n";
	else cout << "Second\n";
}	


int main(){ 

	fio;
	int t;
	t = 1;
	// cin >> t;
	for(int i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solution();
	} 
	return 0;
}
