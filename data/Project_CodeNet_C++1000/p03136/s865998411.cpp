#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int32_t main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  int sum=0;
  
  for(int i=0;i<n;i++)
  {
  cin>>arr[i];
    sum+=arr[i];
  }
  
  int maxi=*max_element(arr.begin(),arr.end());
  sum=sum-maxi;
  if(maxi>=sum)
    cout<<"No"<<endl;
  else
    cout<<"Yes"<<endl;
}