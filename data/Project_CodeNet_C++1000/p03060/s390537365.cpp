
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{

int n;
cin>>n;

int c[n],v[n];
for(int index = 0;index<n;index++)
cin>>v[index];
for(int index = 0;index<n;index++)
cin>>c[index];
int ans = 0;
for(int index = 1;index<=(1<<n);index++)
{
  int curr =0;
  int pos = index;
  for(int i = 0;i<n;i++)
  {
      
      if((pos)&1)
      {
        //  cout<<v[i]<<" "<<c[i]<<endl;
           curr+=(v[i]-c[i]);
      }
      pos/=2;
     
  }
  ans= max(curr,ans);
}

cout<<ans<<endl;
    return 0;
}
