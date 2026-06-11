#include <bits/stdc++.h>
using namespace std;

int main() 
{
      int n,k;
      cin>>n>>k;
      int arr[n];
      for(int i=0; i<n;i++)
      cin>>arr[i];
      vector<bool>dp(k+1); //dp[i] tells if with pile of height i is equal to true
       
       for(int i=0; i<=k; i++)
       {
         for(int j=0; j<n ; j++)
         {
              if(i-arr[j]>=0 && dp[i-arr[j]]==false)
                dp[i]=true;
         }
       }
       if(dp[k])
        cout<<"First"<<endl;
        else
        cout<<"Second"<<endl;
       
        return 0;
}