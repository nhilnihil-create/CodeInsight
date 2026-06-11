#include <bits/stdc++.h>
using namespace std;
int comp(const int &a,const int &b)
{
  return a>b;
}
int main()
{
  int n;
  long long sum=0;
  cin>>n;
  vector<int>a(n);
  vector<int>b(n);
  vector<int>c;
  int count=0;
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<n;i++)cin>>b[i];
  for(int i=0;i<n;i++)
  {
    if(a[i]<b[i])
    {
		sum+=(b[i]-a[i]);
      	count++;
    }
  	if(a[i]>b[i])c.push_back(a[i]-b[i]);
  }
  sort(c.begin(),c.end(),comp);
  int p=0;
  int flag=0;
  while(sum>0)
  {
    sum-=c[p++];
    if(sum>0 && p==c.size())
    {
      flag=1;
      cout<<-1<<endl;
      break;
    }
  }
  if(!flag)cout<<count+p<<endl;
  return 0;
}