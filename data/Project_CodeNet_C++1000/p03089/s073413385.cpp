#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  vector<int>b(n);
  vector<int>a;
  for(int i=0;i<n;i++)cin>>b[i];
  for(int i=0;i<n;i++)
  {
    int x=0,back=1,c;
    for(int i=0;i<n;i++)
    {
      if(back==b[i])
      {
        x=back;
        c=i;
      }
      if(b[i]!=-1)back++;
    }
    if(!x)
    {
      cout<<-1<<endl;
      return 0;
    }
    b[c]=-1;
    a.push_back(x);
  }
  for(int i=a.size()-1;i>=0;i--)cout<<a[i]<<endl;
  return 0;
}