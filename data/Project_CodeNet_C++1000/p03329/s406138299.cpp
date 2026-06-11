#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    int n; cin >> n;
    int dp[n+1]; rep(i,n+1) dp[i] = 1<<30; dp[0] = 0;

    rep(i,n){
        for(int j=1; i+j <= n; j*=6){
            dp[i+j] = min(dp[i+j], dp[i]+1);
        }
        for(int j=1; i+j <= n; j*=9){
            dp[i+j] = min(dp[i+j], dp[i]+1);
        }
    }
    cout << dp[n] << endl;
}