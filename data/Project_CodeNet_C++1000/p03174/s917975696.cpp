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
typedef vector<vi> vvi;
const ll inf = 1000000001, INF = (ll)1e18 + 1;

void solve() {
	int n;
	cin >> n;
	
	vvi can(n, vi(n));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> can[i][j];
			
	vi dp((1 << n));
	dp[0] = 1;
	for(int mask = 0; mask < (1 << n) - 1; mask++) {
		int a = __builtin_popcount(mask);
		for(int j = 0; j < n; j++) {
			if(can[a][j] && !((1 << j) & mask)) {
				dp[mask | (1 << j)] = (dp[mask] + dp[mask | (1 << j)]) % P;
			}
		}
	}
	
	cout << dp[(1 << n) - 1] << endl;
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