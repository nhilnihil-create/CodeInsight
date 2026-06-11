#include<bits/stdc++.h>
using namespace std;

int main()
{
  long long n,z,w;
  
  cin>>n>>z>>w;
  
  long long arr[n];
  
  for(long long i=0;i<n;i++)cin>>arr[i];
  long long a,b;
  if(n==1)
    cout<<abs(arr[0]-w)<<endl;
  else
  {
   	a=abs(arr[n-1]-w);
    b=abs(arr[n-2]-arr[n-1]);
    if(a>b)cout<<a<<endl;
    else cout<<b<<endl;
  }
  
  
  
}
