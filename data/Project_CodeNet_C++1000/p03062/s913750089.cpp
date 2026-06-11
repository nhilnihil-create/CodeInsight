#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int> ;
using vl = vector<ll>;

ll dp[100010][2];

int main(){
    int n;
    cin >> n;
    vi a(n);
    rep(i,n) cin >> a[i];
    rep(i,100010){
        rep(j,2){
            dp[i][j] = 0;
        }
    }
    const ll INF = 1e17;

    dp[0][0] = 0;
    dp[0][1] = -INF;
    rep(i,n){
        dp[i+1][0] = max(dp[i][0]+a[i],dp[i][1]-a[i]);
        dp[i+1][1] = max(dp[i][0]-a[i],dp[i][1]+a[i]);
    }

    cout << dp[n][0] << endl;
    return 0;
}