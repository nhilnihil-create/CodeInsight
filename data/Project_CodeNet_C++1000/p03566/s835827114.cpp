#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;cin>>n;
  vector<int> t(n);
  vector<int> v(n);
  int i,j;
  for(i=0;i<n;i++)cin>>t.at(i);
  for(i=0;i<n;i++)cin>>v.at(i);
  vector<int> sum(n);
  sum.at(0)=t.at(0);
  for(i=1;i<n;i++)sum.at(i)=sum.at(i-1)+t.at(i);
  int tsum=sum.at(n-1);
  vector<int> sp(tsum+1,0);
  vector<int> upper(tsum+1,0);
  vector<int> uppermid(tsum,0);
  int now=1;
  int sec=0;
  while(now<tsum)
  {
    if(now<sum.at(sec))upper.at(now)=v.at(sec);
    else
    {
      upper.at(now)=min(v.at(sec),v.at(sec+1));
      sec++;
    }
    now++;   
  }
  now=0;
  sec=0;
  while(now<tsum)
  {
    if(sum.at(sec)<=now)
    {
      sec++;
      uppermid.at(now)=v.at(sec);
    }
    else uppermid.at(now)=v.at(sec);
    now++;
  }
  for(i=1;i<=100;i++)
  {
    vector<int> spch(tsum+1,0);
    for(j=1;j<tsum;j++)
    {
      if(i<=upper.at(j)&&sp.at(j-1)==sp.at(j)&&sp.at(j)==sp.at(j+1))
      {
        spch.at(j)=i;
      }
    }
    for(j=1;j<tsum;j++)sp.at(j)=max(spch.at(j),sp.at(j));
  }
  double ans=0.0;
  for(i=0;i<tsum;i++)
  {
    if(sp.at(i)!=sp.at(i+1))ans+=double(sp.at(i)+sp.at(i+1))/2;
    else if(sp.at(i)==upper.at(i)&&upper.at(i)==uppermid.at(i))ans+=double(sp.at(i));
    else ans+=double(sp.at(i))+0.25;
  }
  cout<<fixed<<setprecision(10)<<ans<<endl;
}
