#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
const int MAX=1e5+5;
set<pair<int,int> > lef;
set<pair<int,int> > rgt;

int l[MAX];
int r[MAX];

int main()
{
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
  {
    scanf("%d %d",&l[i],&r[i]);
  }
  for(int i=1;i<=n;i++)
  {
    lef.insert(make_pair(-l[i],i));
    rgt.insert(make_pair(r[i],i));
  }
  int cnt=0;
  int cur=0;
  long long ans=0;
  while(lef.size()&&rgt.size())
  {
    cnt++;
    if(cnt%2)
    { 
      pair<int,int> tmp=(*rgt.begin());
      rgt.erase(rgt.begin());
      lef.erase(make_pair(-l[tmp.second],tmp.second));
      if(cur<=r[tmp.second]&&cur>=l[tmp.second])
      {
        continue;
      }
      ans+=abs(cur-tmp.first);
      cur=tmp.first;
    }
    else
    {
      pair<int,int> tmp=(*lef.begin());
      lef.erase(lef.begin());
      rgt.erase(make_pair(r[tmp.second],tmp.second));
      if(cur<=r[tmp.second]&&cur>=l[tmp.second])
      {
        continue;
      }
      ans+=abs(cur+tmp.first);
      cur=-tmp.first;
    }
    
  }
  ans+=abs(cur);
  for(int i=1;i<=n;i++)
  {
    lef.insert(make_pair(-l[i],i));
    rgt.insert(make_pair(r[i],i));
  }
  cnt=0;
  cur=0;
  long long tmpo=0;
  while(lef.size()&&rgt.size())
  {
    cnt++;
    if((cnt%2)==0)
    { 
      pair<int,int> tmp=(*rgt.begin());
      rgt.erase(rgt.begin());
      lef.erase(make_pair(-l[tmp.second],tmp.second));
      if(cur<=r[tmp.second]&&cur>=l[tmp.second])
      {
        continue;
      }
      tmpo+=abs(cur-tmp.first);
      cur=tmp.first;
    }
    else
    {
      pair<int,int> tmp=(*lef.begin());
      lef.erase(lef.begin());
      rgt.erase(make_pair(r[tmp.second],tmp.second));
      if(cur<=r[tmp.second]&&cur>=l[tmp.second])
      {
        continue;
      }
      tmpo+=abs(cur+tmp.first);
      cur=-tmp.first;
    }
  }
  tmpo+=abs(cur);
   printf("%lld\n",max(ans,tmpo));
  

}