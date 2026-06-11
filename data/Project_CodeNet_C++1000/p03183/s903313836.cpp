#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> a;
    rep(i,n){
        vector<ll> b(4);
        cin >> b[1] >> b[2] >> b[3];
        b[0] = b[1] + b[2];
        a.push_back(b);
    }
    sort(a.begin(), a.end());

    ll dp[20005] = {};
    ll ans = 0;
    rep(i,n){
        vector<ll> b = a[i];
        ll w = b[1], s = b[2], v = b[3];
        drep(j,s+1){
            dp[j+w] = max(dp[j+w], dp[j] + v);
            ans = max(ans, dp[j+w]);
        }
    }

    cout << ans << endl;
    return 0;
}


