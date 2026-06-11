#include <bits/stdc++.h>

using namespace std;

const int mxs =  2 * 1e4 + 10;
using ll = long long;

int n;
// vector<ll> w, s, v;

// ll solve(ll mslack, string mask){
//     if(stoi(mask) == 0 || mslack == 0) return 0; // ok for only small value of mask (int)
//     ll res = -1;
//     for(int i = 0; i < n; i++){
//         if((mask[i] - '0') && w[i] <= mslack){
//             string tmp = mask;
//             tmp[i] = '0';
//             res = max(res, v[i] + solve(min(mslack - w[i], s[i]), tmp));
//         }
//     }
//     return res;
// }

struct box{
    ll w, s, v;
    bool operator< (const box& b){
        return w + s > b.w + b.s; //decreasing order
    }
};

vector<box> arr;
vector<vector<ll>> memo;

ll solve(int idx, ll mslack){
    if(idx == n || mslack == 0) return 0;
    if(memo[idx][mslack] != -1) return memo[idx][mslack];
    ll res;
    if(mslack >= arr[idx].w){
        res = max(arr[idx].v + solve(idx+1, min(arr[idx].s, mslack - arr[idx].w)), solve(idx+1, mslack));
    }else{
        res = solve(idx+1, mslack);
    }
    return memo[idx][mslack] = res;
}

int main(){
    cin>>n;
    arr.resize(n);
    for(int i = 0; i < n; i++){
        ll x, y, z;
        cin>>x>>y>>z;
        arr[i] = box();
        arr[i].w = x, arr[i].s = y, arr[i].v = z;
    }
    sort(arr.begin(), arr.end());
    // for(int i = 0; i < n; i++){
    //     cout<<arr[i].v<<endl;
    // }
    // w.resize(n); s.resize(n); v.resize(n);
    // for(int i = 0; i < n; i++){
    //     cin>>w[i]>>s[i]>>v[i];
    // }
    // string mask(n, '1');
    // ll res = solve((ll)1e5, mask);

   
    // vector<ll> mslack(n), dp(n);
    // for(int i = 0; i < n; i++){
    //     dp[i] = arr[i].v;
    //     mslack[i] = arr[i].s;
    // }
    // for(int i = 1; i < n; i++){
    //     for(int j = 0; j < i; j++){
    //         if(mslack[j] >= arr[i].w){
    //             if(arr[i].v + dp[j] > dp[i]){
    //                 dp[i] = arr[i].v + dp[j];
    //                 mslack[i] = min(arr[i].s, mslack[j] - arr[i].w);
    //             }
    //         }
    //     }
    // }
    // ll res = -1;
    // for(auto x : dp){
    //     res = max(res, x);
    // }
    memo.resize(n, vector<ll>(mxs, -1));
    ll res = solve(0, mxs-1);

    cout<<res<<endl;
    return 0;
}