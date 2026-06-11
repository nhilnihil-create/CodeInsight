#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll dp[305][305][305];
ll solve(ll l,ll r,ll k){
    if(k<0)return (-1e9);
    if(r<l+1)return r-l+1;
    if(dp[l][r][k]!=-1)return dp[l][r][k];
    ll &ans = dp[l][r][k];
    ans = max(solve(l+1,r,k),solve(l,r-1,k));
    ll nk = k - (s[l]!=s[r]);
    ans = max(ans , 2 + solve(l+1,r-1,nk));
    return ans;
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll k;cin>>s>>k;
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,s.size()-1,k);
}