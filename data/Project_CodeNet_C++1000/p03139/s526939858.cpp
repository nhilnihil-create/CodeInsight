#include<bits/stdc++.h>
using namespace std;

int main(void)
{
  int n,a,b;
  cin>>n>>a>>b;
  int mx,mi;
  if(a>=b)
    mx=b;
  else
    mx=a;
  if(a+b<=n)
    mi=0;
  else
    mi=a+b-n;
  cout<<mx<<' '<<mi<<endl;
  return 0;
}
