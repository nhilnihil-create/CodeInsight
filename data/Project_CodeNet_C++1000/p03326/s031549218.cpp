#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
  int n,m;cin>>n>>m;
  vector<ll> x(n);
  vector<ll> y(n);
  vector<ll> z(n);
  int i,j;
  ll ans=0;
  rep(i,n)cin>>x[i]>>y[i]>>z[i];
  rep(i,1<<3)
  {
    vector<ll> val(n,0);
    rep(j,n)
    {
      if(i&1<<0)val[j]+=x[j];
      else val[j]-=x[j];
      if(i&1<<1)val[j]+=y[j];
      else val[j]-=y[j];
      if(i&1<<2)val[j]+=z[j];
      else val[j]-=z[j];
    }
    sort(all(val));
    reverse(all(val));
    ll kans=0;
    rep(j,m)kans+=val[j];
    ans=(kans>ans)?kans:ans;
  }
  cout<<ans<<endl;
}
