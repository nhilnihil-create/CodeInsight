#include<bits/stdc++.h>
using namespace std;
int main(){
int dp[222222] = {},p,n;
int mx = 0;
cin>>n;
for (int i=0;i<n;i++) {
cin>>p;
  dp[p]=dp[p-1]+1;
mx=max(mx,dp[p]);
}
cout<<n-mx<<endl;
}