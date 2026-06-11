#include<bits/stdc++.h>
using namespace std;
struct item{
    int a;
    int b;
    int c;
};

int main()
{
    int n;
    cin>>n;
    vector<item> dp(n);
    for(int i=0;i<n;i++){
       int a1,b1,c1;
      cin>>a1>>b1>>c1;
        if(i==0){
            dp[0].a=a1;
            dp[0].b=b1;
            dp[0].c=c1;
        }
        else{
            dp[i].a=max(dp[i-1].b+a1,dp[i-1].c+a1);
            dp[i].b=max(dp[i-1].a+b1,dp[i-1].c+b1);
            dp[i].c=max(dp[i-1].b+c1,dp[i-1].a+c1);
        }
    }
    int ans=max(dp[n-1].a,max(dp[n-1].b,dp[n-1].c));
    cout<<ans<<"\n";
}
