#include<bits/stdc++.h>
using namespace std;
int main()
{  int n;
 cin>>n;
 long int arr[n];
for(int i=0;i<n;i++)
    cin>>arr[i];
long long int ans=0;
 for(int i=0;i<n;i++)
 {  int t=arr[i];
    while(t>0)
    {  if(t%2!=0)
         break;
    t=t/2;
       ans++;
    }
 }
 cout<<ans;
  
  
}