#include<iostream>
#include<vector>
#include<limits>
#include<array>
using namespace std;
typedef long ll;

int main() { 
    ll n;
    cin >> n;
    vector<array<ll, 3>> nums(n);
    for(auto&e:nums) {
        for(auto&a:e)
            cin >> a;
    }

    // cout << "done" << endl;
    vector<array<ll, 3>> dp(n);
    dp[0][0] = nums[0][0];
    dp[0][1] = nums[0][1];
    dp[0][2] = nums[0][2];
    
    for(ll i=1; i < n; i++) { 
        for(ll prev=0; prev < 3; prev++)   
            for(ll curr=0; curr < 3; curr++)
                if(curr!=prev) { 
                    dp[i][curr] = max(dp[i][curr], nums[i][curr] + dp[i-1][prev]);
                }
    }
    ll res = 0;
    for(ll i=0; i <3; i++)
        res = max(res, dp[n-1][i]);
    cout << res << endl;
}