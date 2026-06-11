#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,k;cin>>n>>k;
  vector<long long> x(n);
  vector<long long> y(n);
  int i,j,l;
  for(i=0;i<n;i++)cin>>x.at(i)>>y.at(i);
  vector<pair<long long,long long>> p(n);
  for(i=0;i<n;i++)p.at(i)=make_pair(x.at(i),y.at(i));
  sort(p.begin(),p.end());
  long long ans=4000000000000000001;
  if(k==2)
  {
    for(i=0;i<n;i++)
    {
      for(j=i+1;j<n;j++)
      {
        if(abs(x.at(i)-x.at(j))*abs(y.at(i)-y.at(j))<ans)ans=abs(x.at(i)-x.at(j))*abs(y.at(i)-y.at(j));
      }
    }
  }
  else
  {
    for(i=k;i<=n;i++)
    {
      for(j=0;i+j-1<n;j++)
      {
        long long minx=p.at(j).first;
        long long maxx=p.at(j+i-1).first;
        vector<long long> memoy(0);
        for(l=j+1;l<i+j-1;l++)
        {
          memoy.push_back(p.at(l).second);
        } 
        sort(memoy.begin(),memoy.end());
        long long maxy;
        long long miny;
        long long kans=4000000000000000001;
        long long kmaxy=max(p.at(j).second,p.at(j+i-1).second);
        long long kminy=min(p.at(j).second,p.at(j+i-1).second);
        for(l=0;l<=i-k;l++)
        {
          maxy=max(memoy.at(l+k-3),kmaxy);
          miny=min(memoy.at(l),kminy);
          if(kans>(maxx-minx)*(maxy-miny))kans=(maxx-minx)*(maxy-miny);
        }
        if(kans<ans)ans=kans;
      }
    }
  }
  cout<<ans<<endl;
}
