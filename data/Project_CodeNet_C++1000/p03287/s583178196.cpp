#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  int n,m;
  cin>>n>>m;
  vector<int> a(n);
  int i;
  rep(i,n)cin>>a[i];
  vector<int> sum(n+1,0);
  rep(i,n)sum[i+1]=(sum[i]+a[i])%m;
  map<int,int> maps;
  ll ans=0;
  maps.insert(make_pair(0,1));
  rep(i,n)
  {
    auto it = maps.find(sum[i+1]);
    if(it!=maps.end())
    {
      int ch=maps[sum[i+1]];
      ans+=ch;
      maps[sum[i+1]]=ch+1;
    }
    else
    {
      maps.insert(make_pair(sum[i+1],1));
    }
  }
  cout<<ans<<endl;
}
