#include "bits/stdc++.h"
using namespace std;

int64_t gcm(int64_t x,int64_t y)
{
  if(x%y==0)
   return y;
  return gcm(y,x%y);
}


int main()
{
  int64_t n;
  cin>>n;
  cout<<n*2/gcm(2,n)<<endl;
}