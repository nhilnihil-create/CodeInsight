#include <bits/stdc++.h>
using namespace std;
int main()
{
long long i,j,k,a,b,c=0,d,n,m,t=1,x;
cin>>n>>d>>x;
long long A[n];
for(i=0;i<n;i++)
cin>>A[i];
for(i=0;i<n;i++)
{
  t=1;
  while(t<=d)
  {
    x++;
    t+=A[i];
  }
}
cout<<x<<endl;
return 0;
}
