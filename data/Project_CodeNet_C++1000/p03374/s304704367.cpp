#define _GLIBCXX_DEBUG //test only

#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
typedef pair<ll,ll> P;

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
  set<P> sl;
  ll vsum = 0;
  for(i=n-1;i>=0;i--)
  {
    ans = max(ans,vals[i]);
    if(sl.size() >= 1)
    {
      auto it = sl.end();
      it--;
      P nowp = *it;
      ll kans = vals[i]-x[i]+nowp.first; 
      ans = max(ans,kans);
    }
    vsum += y[i];
    ll val = vsum-(c-x[i]);
    sl.insert(make_pair(val,x[i]));
  }
  

  vector<ll> lvals(n);
  lvals[n-1] = y[n-1]-(c-x[n-1]);
  ll sval = y[n-1];
  for(i=n-2;i>=0;i--)
  {
    lvals[i] = sval+y[i]-(c-x[i]);
    sval += y[i];
  }
  set<P> sr;
  vsum = 0;
  rep(i,n)
  {
    ans = max(ans,lvals[i]);
    if(sr.size() >= 1)
    {
      auto it = sr.end();
      it--;
      P nowp = *it;
      ll kans = lvals[i]-(c-x[i])+nowp.first; 
      ans = max(ans,kans);
    }
    vsum += y[i];
    ll val = vsum-x[i];
    sr.insert(make_pair(val,x[i]));
  }
  cout << ans << endl;
  
}
