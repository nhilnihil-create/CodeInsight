#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
const int p = 1e9 + 7;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> seq(n);
    for(auto &x : seq){
        cin>>x;
    }
    vector<int> dp(k+2);
    dp[0] = 1;
    for(int i=0;i<n;i++){
        for(int j=k,l=0,r=0;j>=0;--j){
            l = r;
            r = dp[j];
            dp[j] = dp[j+1] + dp[max(0, j-seq[i])] - l;  
            dp[j] >=p ? dp[j]-=p : dp[j];
            dp[j] < 0 ? dp[j]+=p : dp[j]; 
        }
    }
    cout<<dp[k]<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}