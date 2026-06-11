#include<bits/stdc++.h>
using namespace std;

int main(void)
{
  int n,k;
  cin>>n>>k;
  if(k+(k-1)<=n)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
  return 0;
}