#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll sz = ((ll)1 << 22);
ll dp[sz];
ll g[22][22];
ll mod = 1e9+7;

int main() {
    ll n;
    cin >> n;
    for(ll i = 0 ; i < n  ;i++){
        for(ll j = 0 ; j < n ; j++)
        cin >> g[i][j];
    }

    dp[0] = 1;
    for(ll mask= 0 ; mask < (1 << n)-1 ; mask++)
    {
        ll i = __builtin_popcount(mask);
        for(ll j = 0 ; j < (n) ; j++)
        {
            if(g[i][j] && !(mask & ((ll)1<< j)))
            {
                ll new_mask = (mask^((ll)1 << j));
                dp[new_mask]+= dp[mask];
                if(dp[new_mask] >= mod)
                dp[new_mask] -= mod;
            }
        }
    }

    cout << dp[((ll)1 << n)-1];




    

}
