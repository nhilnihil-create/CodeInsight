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
const ll inf = 1000000001, INF = (ll)1e18 + 1;

void solve() {
	int n, k;
	cin >> n >> k;
	
	vi dp(k + 1, 0);
	dp[0] = 1;
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		vi fake(k + 1, 0);
		for(int j = k; j >= 0; j--) {
			int tmp = dp[j];
			int l = j + 1, r = min(a + j, k);
			if(r >= l) {
				fake[l] = (fake[l] + tmp) % P;
				if(r + 1 <= k)fake[r + 1] = (fake[r + 1] - tmp + P) % P;
			}
		}
		
		int sum = 0;
		for(int j = 0; j < k + 1; j++) {
			sum = (sum + fake[j]) % P;
			dp[j] = (dp[j] + sum) % P;
		}
	}
	
	cout << dp[k] << endl;
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