#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;

int main(){
    int n;  cin >> n;
    vector<ll> dp(n+1, 1e+15);
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        for(int p6=1; p6<=i; p6*=6)
            dp[i] = min(dp[i], dp[i-p6]+1);
        for(int p9=1; p9<=i; p9*=9)
            dp[i] = min(dp[i], dp[i-p9]+1);
    }
    cout << dp[n] << endl;
    

}