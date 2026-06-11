#include<bits/stdc++.h>

using namespace std;
using ll=long long;

int t;
const ll INF=1e18L+5;

void test_case(){
    int n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0; i<n; i++)cin>>a[i];
    vector<vector<ll>>dp(n+1,vector<ll>(n+1,INF));
    for(int l=n-1; l>=0; l--){
        for(int r=l; r<n; r++){
            ll sm=0;
            for(int i=l; i<=r; i++)sm+=a[i];
            if(l==r)dp[l][r]=0;
            for(int i=l; i<r; i++){
                dp[l][r]=min(dp[l][r], dp[l][i]+dp[i+1][r]+sm);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    t=1;
    while(t--){
        test_case();
    }

    return 0;
}