#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<ll> v(n);
    rep(i,n){
        cin >> v.at(i);
    }

    vector<vector<ll>> dp(n+1,vector<ll>(2));
    dp.at(0).at(1) = -1e10;
    rep(i,n-1){
        dp.at(i+1).at(0) = max(dp.at(i).at(0) + v.at(i), dp.at(i).at(1) - v.at(i));
        dp.at(i+1).at(1) = max(dp.at(i).at(0) - v.at(i), dp.at(i).at(1) + v.at(i));
        // cout << i << " " << dp.at(i+1).at(0) << " " << dp.at(i+1).at(1) << endl;
    }
    dp.at(n).at(0) = dp.at(n-1).at(0) + v.at(n-1);
    dp.at(n).at(1) = dp.at(n-1).at(1) - v.at(n-1);
    // cout << n-1 << " " << dp.at(n).at(0) << " " << dp.at(n).at(1) << endl;
    ll res = max(dp.at(n).at(0),dp.at(n).at(1));
    cout << res << endl;
    return 0;
}