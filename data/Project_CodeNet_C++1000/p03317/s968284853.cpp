#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,m,a;
  cin>>n>>m;
  if(m==2)
    cout<<n-1;
  else
  {
    a=n/(m-1);
    if(a*(m-1)+1<n)
      a++;
    cout<<a;
  }
  return 0;
}
    