#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int arr[n][3];
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<3;j++)
      {
          cin>>arr[i][j];
      }
  }
  for(int i=1;i<n;i++)
  {
      for(int j=0;j<3;j++)
      {
           arr[i][j]=arr[i][j]+max(arr[(i-1)][(j+1)%3],arr[(i-1)][(j+2)%3]);
      }

  }
  cout<<max(arr[n-1][0],max(arr[n-1][1],arr[n-1][2]));

}
