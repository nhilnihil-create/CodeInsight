#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long a,b;
  cin>>a>>b;
  long long pre=0;
  if(a==b)
  {
    cout<<a<<endl;
    return 0;
  }
  long long c=a;
  while((c^(c+1))!=1L && c<b)
  {
    pre^=c;
    c++;
  }
  if(c!=b)
  {
    long long d=(b-c)%4;
    if(d==0)pre^=b;
    else if(d==1)pre^=1;
    else if(d==2)pre^=(b+1);
    else pre^=0;
  }
  cout<<pre<<endl;
  
  return 0;
}
    