#include<bits/stdc++.h>
using namespace std;
#define Intmax 1000000007
int arr[101];
 int dp[100001];
 int k;
 void fun(int n)
 {   
     for(int i=1;i<arr[1];i++)
     {
         dp[i]=0;
     }
     for(int i=arr[1];i<=k;i++)
     {
         int j=1;
         bool yes=0;
         while(i-arr[j]>=0 && j<=n)
         {
             if(dp[i-arr[j]]==0)
             {
                 yes=1;
                 break;
             }
             j++;
         }
         dp[i]=(int)yes;
    }
    return;
 }
int main()
{
  int n;
  cin>>n;
  cin>>k;

  for(int i=1;i<=n;i++)
  {
      cin>>arr[i];
  }
  for(int i=0;i<n+1;i++)
      dp[i]=0;
      fun(n);
      if(dp[k]==1)
      cout<<"First"<<endl;
      else
      cout<<"Second"<<endl;
	return 0;
}
