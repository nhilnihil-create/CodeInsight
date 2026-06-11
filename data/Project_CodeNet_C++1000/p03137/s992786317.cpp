#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,m;
  cin>>n>>m;
  vector<int>a(m);
  
  for(int i=0;i<m;i++)cin>>a[i];
  
  if(n>=m)
  {
    cout<<0<<endl;
    return 0;
  }
  sort(a.begin(),a.end());
  
  vector<int>d(m-1);
  long long  sum=0;
  for(int i=0;i<m-1;i++)
  {
    d[i]=abs(a[i]-a[i+1]);
    sum+=d[i];
  }
  
  sort(d.begin(),d.end());
  int j=m-2;
  while(n>1)
  {
    sum-=d[j--];
    n--;
  }
 cout<<sum<<endl;
  return 0;
}
