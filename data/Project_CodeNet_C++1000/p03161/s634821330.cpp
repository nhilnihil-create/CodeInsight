#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define sp(x) fixed<<setprecision(x)
#define pb push_back
#define eb emplace_back
#define MP make_pair
#define die(x) return cout << x << endl, 0
#define fastio ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0)
const int MAXN = 100 * 1000 + 10;
int n, k, neg;
int a[MAXN], dp[MAXN];
int main(){
    fastio;
    cin >> n >> k;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }
    dp[0] = 0;
    dp[1] = abs(a[1] - a[0]);
//    cout << "dp0: " << dp[0] << endl << "dp1: " << dp[1] << endl;
    for(int i = 2; i < n; i ++){
    	dp[i] = INT_MAX;
    	for(int j = 1; j <= min(k, i); j ++)
        	dp[i] = min(dp[i], dp[i - j] + abs(a[i] - a[i - j]));
//        cout << "dp" << i << ": min( " << dp[i - 1] << " + " << a[i] << " - " << a[i - 1] << ", " << dp[i - 2] << " + " << a[i] << " - " << a[i - 2] << " );\n";
    }
    die(dp[n - 1]);
    return 0;
}
