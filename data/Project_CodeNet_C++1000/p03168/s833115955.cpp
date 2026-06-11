#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){

    int n;
    cin>>n;
    double dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int coin=0;coin<n;coin++){
        double p_head;
        cin>>p_head;
        for(int i=coin+1;i>=0;i--){
            dp[i]=(i==0 ? 0 : dp[i-1]*p_head) + dp[i]*(1-p_head);
        }
    }
    double ans=0;
    for(int head=0;head<=n;head++){
        if(head>n-head){
            ans+=dp[head];
        }
    }
    cout<<fixed<<setprecision(10)<<ans;



return 0;
}
