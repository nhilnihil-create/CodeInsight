#include <bits/stdc++.h>
using namespace std;
long long A[100000];
int main()
{
long long a,b,i,c=1,d=0,n,m,t,j;
cin>>a>>b>>n;
for(i=a;i<=b;i++)
{
  if(i<=a+n-1||i>=b-n+1)
  cout<<i<<endl;
}

return 0;
}
