#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;

void chmax(ll &a, ll b){
    a = max(a, b);
}

int main() {
    int n;
    cin >> n;
    vector<ll> w(n), s(n), v(n);
    vector<P> ord(n);
    for(int i=0;i<n;i++){
        cin >> w[i] >> s[i] >> v[i];
        ord[i] = P(w[i]+s[i],i);
    }
    sort(ord.begin(), ord.end());
    vector<vector<ll> > dp(n+1, vector<ll>(20001,-1));
    dp[0][0] = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=20000;j++){
            if(dp[i][j] < 0) continue;
            ll wi = w[ord[i].second], si = s[ord[i].second], vi = v[ord[i].second];
            chmax(dp[i+1][j], dp[i][j]);
            if(j <= si) chmax(dp[i+1][j+wi], dp[i][j] + vi);
        }
    }
    ll ans = 0;
    for(int i=0;i<=20000;i++){
        chmax(ans, dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}
