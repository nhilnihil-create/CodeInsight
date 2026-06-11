#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int mod = 1e9 + 7;
const int MAX = 510000;


int main() {
    ll n; cin >> n;
    vl a(n);
    rep(i,n) cin >> a[i];
    vl dp(n+1,0);
    dp[0] = 1;
    vl table(200005,-1);
    rep(i,n){
        dp[i+1] = dp[i];
        if(table[a[i]] != -1){
            if(a[i-1]==a[i]) continue;
            dp[i+1] += dp[table[a[i]]+1];
            dp[i+1] %= mod;
        }
        table[a[i]] = i;
    }
    cout << dp[n] << endl;
}