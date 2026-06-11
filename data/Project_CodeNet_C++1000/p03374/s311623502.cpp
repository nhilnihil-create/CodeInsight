#define _GLIBCXX_DEBUG //test only

#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
typedef pair<ll,ll> P;
#define MIN -12345678901234567

int main()
{
  int n;
  ll c;
  cin >> n >> c;
  vector<ll> x(n);
  vector<ll> y(n);
  int i;
  rep(i,n) cin >> x[i] >> y[i];
  vector<ll> vals(n);
  vals[0] = y[0]-x[0];
  ll now = x[0];
  rep(i,n-1)
  {
    vals[i+1] = vals[i]+y[i+1]-(x[i+1]-now);
    now = x[i+1];
  }
  ll ans = 0;
  ll sl = MIN;
  ll vsum = 0;
  for(i=n-1;i>=0;i--)
  {
    ans = max(ans,vals[i]);
    if(i != n-1)
    {
      ll kans = vals[i]-x[i]+sl; 
      ans = max(ans,kans);
    }
    vsum += y[i];
    ll val = vsum-(c-x[i]);
    sl = max(sl,val);
  }
  

  vector<ll> lvals(n);
  lvals[n-1] = y[n-1]-(c-x[n-1]);
  ll sval = y[n-1];
  for(i=n-2;i>=0;i--)
  {
    lvals[i] = sval+y[i]-(c-x[i]);
    sval += y[i];
  }
  ll sr = MIN;
  vsum = 0;
  rep(i,n)
  {
    ans = max(ans,lvals[i]);
    if(i != 0)
    {
      ll kans = lvals[i]-(c-x[i])+sr; 
      ans = max(ans,kans);
    }
    vsum += y[i];
    ll val = vsum-x[i];
    sr = max(sr,val);
  }
  cout << ans << endl;
}
