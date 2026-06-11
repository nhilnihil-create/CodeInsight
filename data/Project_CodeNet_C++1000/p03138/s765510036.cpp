#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using ll = long long;
using P = pair<int, int>;
#define debug(var) cout << "[" << #var << "] " << var << endl
const ll mod = 1000000007;

ll dp[65][2];

int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll now = 0;
    ll ans = 0;
    

    for (int i=60; i>=0; i--){
        ll num = 0;
        rep(j, n) {
            if ((a[j]>>i & 1)==1) num++;
        }
        ll ik = (k>>i) & 1;
        if (ik==0) {
            dp[i][0] = dp[i+1][0] + (num * (1LL<<i));
        }
        else {
            dp[i][0] = dp[i+1][0] + ((n-num) * (1LL<<i));
        }
        if (dp[i+1][1]) {
            dp[i][1] = dp[i+1][1] + (max(num, n-num) * (1LL<<i));
        }
        if (ik==1) {
            dp[i][1] = max(dp[i][1], dp[i+1][0] + (num * (1LL<<i)));
        }
        //debug(dp[i][0]);
        //debug(dp[i][1]);
        /*
        if ((1LL<<i)+now>k) {
            ans += (1LL<<i)*(num);
        }
        else if (num>n/2) {
            now += 1LL<<i;
            ans += (1LL<<i)*num;
        }
        else {
            ans += (1LL<<i)*(n-num);
        }
        */
    }
    ans = max(dp[0][0], dp[0][1]);  
    
    cout << ans << endl;
    return 0;
}
