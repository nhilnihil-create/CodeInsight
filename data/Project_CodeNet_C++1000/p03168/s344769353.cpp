#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9+5;
const ll INFLL = 1e18l+5;

int main(){
    int n;
    cin>>n;
    vector<double> dp(n+1); //dp[i] is probability of getting i heads
    dp[0]=1;
    for(int coin=0; coin<n; ++coin){
        double phead;
        cin>>phead;
        for(int i=coin+1; i>=0; --i){
            if(i==0) dp[i]= dp[i]*(1-phead);
            else if(i==coin+1) dp[i]=dp[i-1]*phead;
            else dp[i]=dp[i-1]*phead+dp[i]*(1-phead);
        }
    }
    double ans=0;
    int i = n%2==0 ? n/2 : n/2+1;
    for(i=i; i<=n; ++i){
        ans+=dp[i];
    }

    printf("%.9f",ans);

    


}