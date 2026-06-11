#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x)      begin(x),end(x)

using namespace std;
using vecint = vector<int>;
using ll = int64_t;
constexpr ll INF = 1000000000000000000ll;

int main()
{
  int n;
  cin>>n;
  vector<int64_t> a(n);
  for(auto&& e:a) cin>>e;
  ll mn = INF;
  vector<int64_t> psum(n+1);
  partial_sum(ALL(a), begin(psum)+1);
  FOR(i,2,n-1) {
    ll x = psum[i];
    ll y = psum.back() - x;
    auto idx1 = lower_bound(begin(psum),begin(psum)+i+1,(x+1)/2) - begin(psum);
    ll p = psum[idx1], q = x-p;
    ll lg1 = INF;
    ll sm1 = 0;
    if (idx1 < i) {
      lg1 = min(lg1, max(p, q));
      sm1 = max(sm1, min(p, q));
    }
    if (idx1>1) {
      --idx1;
      p = psum[idx1];
      q = x-p;
      lg1 = min(lg1, max(p, q));
      sm1 = max(sm1, min(p, q));
    }
    auto idx2 = lower_bound(begin(psum)+i,end(psum),x+(y+1)/2) - begin(psum);
    ll r = psum[idx2]-x, s = y-r;
    ll lg2 = INF;
    ll sm2 = 0;
    if (idx2 < n) {
      lg2 = min(lg2, max(r, s));
      sm2 = max(sm2, min(r, s));
    }
    if (idx2>i+1) {
      --idx2;
      r = psum[idx2]-x;
      s = y-r;
      lg2 = min(lg2, max(r, s));
      sm2 = max(sm2, min(r, s));
    }
    ll lg = max(lg1, lg2);
    ll sm = min(sm1, sm2);
    mn = min(mn, lg - sm);
  }
  cout << mn << endl;
  return 0;
}
