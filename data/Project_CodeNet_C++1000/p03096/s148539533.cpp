#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007;

ll dp[200005];
vector<ll> pos[200005];
int main(void){
    ll n;
    cin >> n;


    ll c[n];
    rep(i, 0, n){
        cin >> c[i];
        c[i]--;
        pos[c[i]].push_back(i);
    }

    dp[0] = 1;
    rep(i, 1, n){
        dp[i] = dp[i - 1];
        ll prev = lower_bound(pos[c[i]].begin(), pos[c[i]].end(), i) - pos[c[i]].begin() - 1;

        if(prev < 0) continue;
        if(i - pos[c[i]][prev] > 1){
            dp[i] += dp[pos[c[i]][prev]];
            dp[i] %= MOD;
        }
    }

    cout << dp[n - 1] << endl;
    return 0;
}
