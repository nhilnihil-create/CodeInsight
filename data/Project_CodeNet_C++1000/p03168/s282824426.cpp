#include<bits/stdc++.h>

using namespace std;
using ll=long long;

int t;

void test_case(){
    int n;
    cin>>n;
    vector<double>dp(n+1);
    dp[0]=1; // P(having 0 heads outoff 0 coins) = 1
    for(int coin=1; coin<=n; coin++){
        double p_head;
        cin>>p_head;
        double p_tail=(1-p_head);
        for(int n_heads=coin; n_heads>=0; n_heads--){
            dp[n_heads]=((n_heads ? dp[n_heads-1] : 0)*p_head) + (dp[n_heads]*p_tail);
        }
    }
    double ans=0;
    for(int n_head=0; n_head<=n; n_head++){
        if(n_head>(n-n_head)){
            // cout<<dp[n_head]<<" "<<n_head<<endl;
            ans+=dp[n_head];
        }
    }
    cout<<setprecision(10)<<ans<<endl;
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