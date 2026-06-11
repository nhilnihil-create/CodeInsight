#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
const ll inf = 1e11;
int main(){
    ll n,m; cin >> n >> m;
    vector<ll> a(m);
    rep(i,m) cin >> a[i];
    sort(a.rbegin(), a.rend());
    ll cnt[9] = {2,5,5,4,5,6,3,7,6};
    vector<ll> dp(n+1,-inf);
    dp[0] = 0;

    rep(i,n+1){
        rep(j,m){
            if(i >= cnt[a[j]-1]){
                dp[i] = max(dp[i - cnt[a[j]-1]] + 1,dp[i]);
            }
        }
    }

    ll now = n;
    
    rep(i,m){
        while(dp[now - cnt[a[i]-1]] == dp[now] - 1){
            cout << a[i];
            now -= cnt[a[i]-1];
        }
    }

    cout << endl;
}
