#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll arr[501];
ll dp[501][501];
ll prefix[501];
ll solve(int l, int r){
    if(l == r) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    ll mina = 1e18;
    for(int x=1;x<=r-l;x++){
        ll pre = prefix[l+x-1] -  prefix[l-1];
        ll suf = prefix[r] - prefix[l+x-1];
        mina = min(mina, pre + suf + solve(l, l+x-1) + solve(l+x, r));
    }
    return dp[l][r] = mina;
}
int main(){
    memset(dp, -1, sizeof dp);
    cin>>n;
    for(int x=1;x<=n;x++){
        cin>>arr[x];
        prefix[x] += arr[x] + prefix[x-1];
    }
    cout<<solve(1, n);


}
