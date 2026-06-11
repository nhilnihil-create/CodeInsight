#include<bits/stdc++.h>

using namespace std;
int n;
int arr[100009][4];
int dp[100009][4];

int dp_na_pari(int ind, int pos)
{
    if(ind==n-1)
        return arr[ind][pos];
    if(ind>=n)
        return 0;
    if(dp[ind][pos]!=-1)
        return dp[ind][pos];
    int ans=INT_MIN;
    if(pos==0)
    {
        ans=max(arr[ind][pos]+dp_na_pari(ind+1,1),arr[ind][pos]+dp_na_pari(ind+1,2));
    }
    else if(pos==1)
    {
        ans=max(arr[ind][pos]+dp_na_pari(ind+1,2),arr[ind][pos]+dp_na_pari(ind+1,0));
    }
    else
    {
        ans=max(arr[ind][pos]+dp_na_pari(ind+1,1),arr[ind][pos]+dp_na_pari(ind+1,0));
    }
    return dp[ind][pos]=ans;
}
int main()
{
    memset(dp,-1,sizeof dp);
   cin>>n;

   for(int i=0;i<n;i++)
   {
       for(int j=0;j<3;j++)
        cin>>arr[i][j];
   }
   int ans=INT_MIN;
   for(int i=0;i<3;i++)
    ans=max(ans,dp_na_pari(0,i));
   cout<<ans<<endl;

}
