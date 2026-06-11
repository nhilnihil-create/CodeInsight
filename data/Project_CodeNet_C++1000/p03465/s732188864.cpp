#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,i,j,sum=0;
  cin>>n;
  bitset<2000001> b;
  b.reset();
  b[0]=1;
  for(i=0;i<n;i++)
  {
    cin>>j;
    sum+=j;
    b|=b<<j;
  }
  for(i=(sum+1)/2;;i++)
    if(b[i])
      break;
  cout<<i;
  return 0;
}