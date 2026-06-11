#include <bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define ff first
#define ss second
#define P 1000000007
#define in(x, a, b) (a <= x && x < b)
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)

using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
const ll inf = 1000000001, INF = (ll)1e18 + 1, maxn = 405;

void solve() {
	int n;
	cin >> n;
	
	vi a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	
	vector<vector<ll>> dp(maxn, vector<ll>(maxn, INF));
	for(int l = n - 1; l >= 0; l--) {
		for(int r = l; r < n; r++) {
			if(r == l) dp[l][r] = 0;
			else {
				ll cost = 0;
				for(int i = l; i <= r; i++) cost += a[i];
				for(int i = l; i <= r; i++) {
					dp[l][r] = min(dp[l][r], dp[l][i] + dp[i + 1][r] + cost);
				}
			}
		} 
	}
	
	cout << dp[0][n - 1] << endl;
}

int main(){
#define MULTITEST 0
#if MULTITEST   
 
    CASET {
        solve();
    }
    
#else

    solve();
    
#endif

    return 0;
}