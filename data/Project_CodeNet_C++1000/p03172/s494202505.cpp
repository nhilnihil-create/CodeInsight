#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#define ll long long int
#define ld long double
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define mod(n) (n) % 1000000007
#define sp << " "
#define precision(n) cout << fixed << setprecision(n);
#define startTime time_t start, end;time(&start);
#define endTime time(&end);double tt = double(end-start);cout<<"Time taken : "<<fixed<<tt<<setprecision(5);cout <<" sec"<< endl;
 
using namespace std;
 
int main() { 
    IOS;
    ll n, k;
    cin >> n >> k;
    vll a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    ll dp[n][k + 1];
    ll cum[n][k + 1];
    memset(dp, 0, sizeof dp);
    memset(cum, 0, sizeof cum);
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < k + 1; j++) {
    		if (i == 0) {
    			dp[i][j] = (a[i] >= j)? 1: 0;
    		}
    		else {
    			if (j - (a[i] + 1) < 0) dp[i][j] = mod(cum[i - 1][j]);
    			else dp[i][j] = mod(1000000007 + mod(cum[i - 1][j]) - mod(cum[i - 1][j - (a[i] + 1)]));
    		}
    		
    		if (j > 0) cum[i][j] = mod(mod(dp[i][j]) + mod(cum[i][j - 1]));
    		else cum[i][j] = mod(dp[i][j]);
    	}
    }
    cout << dp[n - 1][k] << endl;
}