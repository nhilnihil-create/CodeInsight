#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  int n;cin>>n;
  vector<int> a(n);
  vector<int> b(n);
  int i;
  rep(i,n)cin>>a[i];
  rep(i,n)cin>>b[i];
  vector<int> dis(n);
  rep(i,n)dis[i]=a[i]-b[i];
  ll disp=0;
  ll dism=0;
  int countm=0;
  sort(all(dis));
  reverse(all(dis));
  rep(i,n)
  {
    if(dis[i]>=0)disp+=dis[i];
    else
    {
      dism+=dis[i];
      countm++;
    }
  }
  if(disp+dism<0)cout<<-1<<endl;
  else
  {
    int now=0;
    while(dism<0)
    {
      dism+=dis[now];
      now++;
    }
    cout<<now+countm<<endl;
  }
}
