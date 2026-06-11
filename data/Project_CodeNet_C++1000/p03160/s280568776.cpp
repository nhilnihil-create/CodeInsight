#include<bits/stdc++.h>
using namespace std;
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int mod=10e8+7;

int getmax(int n,int ar[])
{

    vector<int>dp(n,INT_MAX);
  
    int i,j,res,ans1,ans2,ans3;
      dp[0]=0;
      dp[1]=abs(ar[1]-ar[0]);
   
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<=i+2;j++)
        if(j<n)
        dp[j]=min(dp[j],dp[i]+abs(ar[j]-ar[i]));
    }
  
    return dp[n-1];

    

}
int main()
{
    int T,n,sum;
    
    
   
        cin>>n;
        int ar[n];
        for(int i=0;i<n;i++)
        cin>>ar[i];
        cout<<getmax(n,ar)<<"\n";
    
}