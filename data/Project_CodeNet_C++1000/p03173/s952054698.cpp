#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[405][405];
const ll INF = 1e18+5; 
int main() {
    int n;
    cin>>n;
    vector<ll> a(n),sum(n+1,0);
    for(int i =0;i<n;i++) {
        cin>>a[i];
        sum[i+1] = sum[i] + a[i];
    }
    auto get = [&](int l,int r) {
        return sum[r+1] - sum[l];
    };
    for(int l = n-1;l>=0;l--) {
        for(int r = l;r<n;r++) {
            if(l == r) {
                dp[l][r] = 0;
            } else {
                dp[l][r] = INF;
                for(int i = l;i<=r-1;i++) {
                    dp[l][r] = min(dp[l][r],dp[l][i] + dp[i+1][r] + get(l,r));
                }
            }
        }
    } 
    cout<<dp[0][n-1]<<"\n";   
}