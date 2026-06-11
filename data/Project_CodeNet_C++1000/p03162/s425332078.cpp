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
int a[MAXN][3], dp[MAXN][3];
int main(){
    fastio;
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    for(int i = 0; i < 3; i ++)dp[0][i] = a[0][i]/*, cout << 0 << ", " << i << ": " << a[0][i] << '\t'*/;
    //cout << endl;
    for(int i = 1; i < n; i ++){
    	for(int j = 0; j < 3; j ++){
    		dp[i][j] = INT_MIN;
    		//cout << i << ", " << j << ": ";
    		int mx = INT_MIN;
    		for(int k = 0; k < 3; k ++)if(k != j)mx = max(mx, dp[i - 1][k]);
    		//cout << mx << " + " << a[i][j] << '\t';
    		dp[i][j] = mx + a[i][j];
    	}
		//cout << endl;
    }
    die(max(max(dp[n - 1][1], dp[n - 1][2]), dp[n - 1][0]));
    return 0;
}