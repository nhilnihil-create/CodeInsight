#include<bits/stdc++.h>
using namespace std;
vector<int> dp(100000,0);
 
int main(){
    int n;cin>>n;
    int a,b,c;
    a=1;b=6;c=9;
    for(int i=1;i<n+1;i++){
        if(i>=b*6) b*=6;
        if(i>=c*9) c*=9;
        if(i<6) dp[i]=i;
        else if(i<9) dp[i]=min(dp[i-a]+1,dp[i-b]+1);
        else dp[i]=min({dp[i-a]+1,dp[i-b]+1,dp[i-c]+1});
    }
    cout<<dp[n]<<endl;
}