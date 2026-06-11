#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
vector<vector<int>>a;
int n;
ll dp[25][1<<22];
ll  rec(int curr,int mask) {
    if(curr == n) return 1;
    if(dp[curr][mask]!=-1) return dp[curr][mask];
    ll ans = 0;
    for(int i = 0;i<n;i++) {
        if(a[curr][i]== 1 && !(((1<<i)& mask)==(1<<i))) {
            ans = (ans + rec(curr+1,mask|(1<<i)))%mod;
        }
    }
    return dp[curr][mask] = ans;
}
int main() {
    cin>>n;
    memset(dp,-1,sizeof(dp));
    a.resize(n,vector<int>(n));
    for(int i =0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    cout<<rec(0,0)<<"\n";
}