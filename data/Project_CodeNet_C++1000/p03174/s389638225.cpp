#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
// #define endl "\n"
#define MOD 1000000007

ll recurse(ll i, ll women, vector<vector<ll>>& his, vector<vector<ll>>& dp, ll n) {
    if (women == (1<<n) - 1) {
        // all women done => all men have to be done
        return 1;
    }

    if (i == n) {
        // all men done but not women
        return 0;
    }

    // all women done but men not is not possible

    // no one is done
    if (dp[i][women] != -1) {
        return dp[i][women];
    }

    ll ans = 0;
    for (auto w: his[i]) {
        //  if no women for this man, then ans is 0 from here
        if (!(women & (1<< w))) {
            ans = (ans + recurse(i+1, women | (1<<w), his, dp, n)) % MOD;
        }
    }
    return dp[i][women] = ans;
}



int main(void) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    ll n;
    cin >> n;
    vector<vector<ll>> his (n);
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            ll a;
            cin >> a;
            if (a) {
                his[i].push_back(j);
            }
        }
    }
    vector<vector<ll>> dp (n, vector<ll> (1 << 21 + 1, -1));
    cout << recurse(0, 0, his, dp, n) << endl;

    
    return 0;
}