#include<bits/stdc++.h>
#define m 1000000007
using namespace std;
int main()
 {
     int n;
     cin>>n;
     bitset <4000000> dp;
     int ar[n];
     int sum=0;
     for(int i=0;i<n;i++)
     {
         cin>>ar[i];
         sum+=ar[i];
     }
     dp[0]=1;
     for(int i=0;i<n;i++)
     {
         dp|=(dp<<ar[i]);
     }
     int odd=sum%2;
     for(int i=sum/2+odd;i<=sum;i++)
     {
         if(dp[i]==1)
         {
             cout<<i<<endl;
             return 0;
         }
     }
}