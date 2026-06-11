#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
int n,k;
cin>>n>>k;
vector<int> v;
for(int i=0;i<n;i++)
{   int x;
    cin>>x;
    v.push_back(x);

}
vector<int> dp(n,0);
for(int i=n-2;i>=0;i--)
{
    dp[i]=INT_MAX;
    for(int j=1;j<=k;j++)
    {
      if(j+i==n)
            break;
      dp[i]=min(dp[i],dp[i+j]+abs(v[i]-v[i+j]));

    }
  

}
cout<<dp[0];
    return 0;
}

