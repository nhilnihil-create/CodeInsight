#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define int ll

typedef pair<int,int> pi;
typedef vector<int> vi;
 
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define pb push_back

template<typename T> void max_self(T &a, T b) { a = max(a,b); return;}
template<typename T> void min_self(T &a, T b) { a = min(a,b); return;}
 
const int nax = 3e6 + 5;
const int mod = 1e9 + 7;

int solve(int a,int b,int c){
	
	a = a % c;	
	if(b == 0) return 1;
	else if((b % 2) == 0) return solve((a * a) % c,b / 2,c) % c;
	else return (a * solve((a * a) % c,b / 2,c) % c) % c;
}

int n;
int dp[1 << 21];

signed main(){
	
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	//cin >> t;
	while(t--){
		cin >> n;
		
		int arr[n][n];
		for(int i = 0; i < n ; ++i){
			for(int j = 0; j < n; ++j){
				cin >> arr[i][j];
			}
		}
		
		memset(dp,0,sizeof(dp));
		dp[0] = 1;
		
		for(int mask = 0; mask < (1 << n) - 1; ++mask){
			int women = __builtin_popcount(mask);
			for(int i = 0; i < n; ++i){
				if((mask & (1 << i)) == 0 && arr[i][women]){
					int newmask = mask | (1 << i);
					dp[newmask] = (dp[newmask] + dp[mask]) % mod;
				}
			}
		}
		
		cout << dp[(1 << n) - 1];
	}
	
	return 0;
}
