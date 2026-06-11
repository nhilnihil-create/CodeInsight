#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  int sum=0;
  for(int i=0;i<n;i++)
    sum+=arr[i];
  bitset<4000001> b;
  b[0]=1;int ans=0;
  if(n==0) cout<<"0"<<endl;
  else if(n==1) cout<<arr[0]<<endl;
  else if(n==2) cout<<max(arr[0],arr[1])<<endl;
  else
  {
    for(int i=0;i<n;i++)
      b=b | (b << arr[i]);
    for(int i=(sum+1)/2;i<=sum;i++)
    {
      if(b[i])
      {
        ans=i;
        break;
      }
    }
    cout<<ans<<endl;
  }
}