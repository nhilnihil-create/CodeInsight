#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,k;
  cin>>n>>k;
  int arr[n],cost[n]={0};
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }

  for(int i=1;i<n;i++)
  {if(k>0)
     {int mini=INT_MAX;
      for(int j=1;j<=min(k,i);j++)
      {
          mini=min(mini,cost[i-j]+abs(arr[i]-arr[i-j]));
      }
      cost[i]=mini;
     }
  }

  cout<<cost[n-1];

}
