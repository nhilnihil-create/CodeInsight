#include "bits/stdc++.h"
using namespace std;

int main()
{
  int x,ans;
  ans=0;
  cin>>x;
  if(x>=105)
    ans++;
  if(x>=135)
    ans++;
  if(x>=165)
    ans++;
  if(x>=189)
    ans++;
  if(x>=195)
    ans++;
  cout<<ans<<endl;
}